#include "UCPE.hpp"

// About: Function for finding of address in region
// Param 1: address
// Param 2: Region name for finding
// Mode: Usermode + Kernelmode
bool PeEmulation::FindAddressInRegion(
	_In_ DWORD_PTR address, 
	_Inout_ std::stringstream& RegionName,
	_In_opt_ bool FindInModules,
	_In_opt_ bool FindInStack,
	_In_opt_ bool FindInHeap)
{
	if (FindInModules)
	{
		for (size_t i = 0; i < m_FakeModules.size(); ++i)
		{
			if (address >= m_FakeModules[i]->ImageBase && address < m_FakeModules[i]->ImageBase + m_FakeModules[i]->ImageSize)
			{
				std::string dllname;
				UnicodeToANSI(m_FakeModules[i]->DllName, dllname);
				RegionName << dllname << "+" << std::uppercase << std::hex << (address - m_FakeModules[i]->ImageBase);
				return true;
			}
		}
	}

	if (FindInStack)
	{
		if (address >= m_StackBase && address < m_StackEnd)
		{
			RegionName << "StackBase+" << std::hex << (address - m_StackBase);
			return true;
		}
	}

	if (FindInHeap)
	{
		if (address >= m_HeapBase && address < m_HeapEnd)
		{
			RegionName << "HeapBase+" << std::hex << (address - m_HeapBase);
			return true;
		}
	}

	if (!m_IsKernel)
	{
		if (address >= m_PebBase && address < m_PebEnd)
		{
			RegionName << "Peb+" << std::hex << (address - m_PebBase);
			return true;
		}

		if (address >= m_TebBase && address < m_TebEnd)
		{
			RegionName << "Teb+" << std::hex << (address - m_TebBase);
			return true;
		}
	}
	else
	{
		if (address >= m_DriverObjectBase && address < m_DriverObjectBase + sizeof(DRIVER_OBJECT))
		{
			RegionName << "DriverObject+" << std::hex << (address - m_DriverObjectBase);
			return true;
		}
	}

	if (address >= m_KSharedUserDataBase && address < m_KSharedUserDataEnd)
	{
		RegionName << "KSharedUserData+" << std::hex << (address - m_KSharedUserDataBase);
		return true;
	}

	return false;
}

// About: Function for finding of section by address
// Param 1: address 
// Param 2: our section(aka 'FakeSection') 
// Mode: Usermode + Kernelmode
bool PeEmulation::FindSectionByAddress(_In_ DWORD_PTR address, _Inout_ FakeSection** section)
{
	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		auto& m = m_FakeModules[i];
		if (address >= m->ImageBase && address < m->ImageBase + m->ImageSize)
		{
			for (size_t j = 0; j < m->FakeSections.size(); ++j)
			{
				auto r = &m->FakeSections[j];
				if (address >= m->ImageBase + r->SectionBase && address < m->ImageBase + r->SectionBase + r->SectionSize)
				{
					*section = r;
					return true;
				}
			}

			break;
		}
	}
	return false;
}

// About: Function for finding of API by address
// Mode: Usermode + Kernelmode
bool PeEmulation::FindAPIByAddress(_In_ DWORD_PTR address, _Inout_ std::wstring& DllName, _Inout_ FakeAPI** api)
{
	std::vector<std::thread> threads;
	std::atomic<bool> found(false);
	std::mutex mtx;
	std::condition_variable cv;

	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		threads.emplace_back([&, i]() {
			auto& m = m_FakeModules[i];
			if (address >= m->ImageBase && address < m->ImageBase + m->ImageSize)
			{
				std::unique_lock<std::mutex> lock(mtx);
				DllName = m->DllName;

				for (size_t j = 0; j < m->FakeAPIs.size(); ++j)
				{
					auto r = &m->FakeAPIs[j];
					if (r->VirtualAddress == address)
					{
						*api = r;
						found.store(true);
						lock.unlock();
						cv.notify_all();// Notify all pending threads
						return;
					}
				}
			}
			});
	}

	// Waiting for one of the threads to finish
	{
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [&] { return found.load(); });
	}

	// Termination of all threads
	for (auto& t : threads)
	{
		if (t.joinable())
			t.join();
	}

	return found.load();
}

// About: Function for finding of module by address
// Mode: Usermode + Kernelmode
bool PeEmulation::FindModuleByAddress(_In_ DWORD_PTR address, _Inout_ DWORD_PTR& DllBase)
{
	if (address >= m_ImageBase && address < m_ImageEnd)
	{
		DllBase = m_ImageBase;
		return true;
	}

	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		auto& m = m_FakeModules[i];
		if (address >= m->ImageBase && address < m->ImageBase + m->ImageSize)
		{
			DllBase = m->ImageBase;
			return true;
		}
	}
	return false;
}