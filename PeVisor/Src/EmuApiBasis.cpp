#include "UCPE.hpp"

extern std::ostream* outs;

void PeEmulation::AddAPIEmulation(_Inout_ PFakeAPI FApi, _Out_ PVOID callback)
{
	FApi->EmuCallback = callback;

	if (callback)
	{
		uc_err err;

		const unsigned char Code[] = "\xC3";
		err = uc_mem_write(m_uc, FApi->VirtualAddress, Code, sizeof(Code));
	}
}

bool PeEmulation::RegisterAPIEmulation(
	_In_ const std::wstring& DllName, 
	_In_ const char* ProcedureName,
	_In_ PVOID callback)
{
	std::vector<std::thread> threads;
	std::mutex mtx;
	std::condition_variable cv;
	bool found = false;

	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		threads.emplace_back([&, i]() {
			auto& m = m_FakeModules[i];
			if (!_wcsicmp(m->DllName.c_str(), DllName.c_str()))
			{
				for (size_t j = 0; j < m->FakeAPIs.size(); ++j)
				{
					if (m->FakeAPIs[j].ProcedureName == ProcedureName)
					{
						std::unique_lock<std::mutex> lock(mtx);
						AddAPIEmulation(&m->FakeAPIs[j], callback);
						found = true;
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
		cv.wait(lock, [&] { return found; });
	}

	// Completion of all threads
	for (auto& t : threads)
	{
		if (t.joinable())
			t.join();
	}

	if (!found)
	{
		*outs << "failed to register API emulation for " << ProcedureName << "\n";
	}

	return found;
}