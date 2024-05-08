#include "UCPE.hpp"

// About: Function for stack allocation
// Param 1: size of bytes
// Mode: Usermode + Kernelmode
DWORD_PTR PeEmulation::StackAlloc(_In_ size_t AllocBytes)
{
	DWORD_PTR rsp;
	uc_reg_read(m_uc, UC_X86_REG_RSP, &rsp);
	rsp -= AllocBytes;
	uc_reg_write(m_uc, UC_X86_REG_RSP, &rsp);
	return rsp;
}

// About: Function for stack free
// Param 1: size of bytes
// Mode: Usermode + Kernelmode
void PeEmulation::StackFree(_In_ size_t AllocBytes)
{
	DWORD_PTR rsp;
	uc_reg_read(m_uc, UC_X86_REG_RSP, &rsp);
	rsp += AllocBytes;
	uc_reg_write(m_uc, UC_X86_REG_RSP, &rsp);
}

// About: Function for heap allocation
// Param 1: size of bytes
// Param 2: page alignment
// Mode: Usermode + Kernelmode
DWORD_PTR PeEmulation::HeapAlloc(_In_ size_t AllocBytes, _In_opt_ bool IsPageAlign)
{
	DWORD_PTR alloc = 0;

	for (size_t i = 0; i < m_HeapAllocs.size(); ++i)
	{
		if (m_HeapAllocs[i].free && m_HeapAllocs[i].size >= AllocBytes)
		{
			m_LastHeapAllocBytes = AllocBytes;
			m_HeapAllocs[i].free = false;
			alloc = m_HeapAllocs[i].base;
			break;
		}
	}

	if (!alloc)
	{
		for (size_t i = 0; i < m_HeapAllocs.size(); ++i)
		{
			if (alloc < m_HeapAllocs[i].base + m_HeapAllocs[i].size)
				alloc = m_HeapAllocs[i].base + m_HeapAllocs[i].size;
		}

		if (!alloc)
			alloc = m_HeapBase;

		if (IsPageAlign)
		{
			alloc = (alloc % 0x1000ull == 0) ? alloc : AlignSize(alloc, 0x1000ull);
			AllocBytes = (AllocBytes % 0x1000 == 0) ? AllocBytes : (ULONG)AlignSize(AllocBytes, 0x1000);
		}

		if (alloc + AllocBytes > m_HeapEnd)
		{
			m_LastHeapAllocBytes = 0;
			return 0;
		}

		m_LastHeapAllocBytes = AllocBytes;
		m_HeapAllocs.emplace_back(alloc, AllocBytes);
	}

	return alloc;
}

// About: Function for heap free
// Param 1: size of bytes
// Mode: Usermode + Kernelmode
bool PeEmulation::HeapFree(_In_ DWORD_PTR FreeAddress)
{
	DWORD_PTR maxaddr = 0;

	for (size_t i = 0; i < m_HeapAllocs.size(); ++i)
	{
		if (maxaddr < m_HeapAllocs[i].base)
			maxaddr = m_HeapAllocs[i].base;
	}

	for (size_t i = 0; i < m_HeapAllocs.size(); ++i)
	{
		if (!m_HeapAllocs[i].free && m_HeapAllocs[i].base == FreeAddress)
		{
			if (maxaddr == FreeAddress)
				m_HeapAllocs.erase(m_HeapAllocs.begin() + i);
			else
				m_HeapAllocs[i].free = true;
			return true;
		}
	}
	return false;
}

// About: Function for create memory mapping
// Param 1: src address
// Param 2: dst address
// Param 3: size of bytes
// Mode: Usermode + Kernelmode
bool PeEmulation::CreateMemMapping(_In_ DWORD_PTR BaseAddress, _In_ DWORD_PTR MapAddress, _In_ size_t Bytes)
{
	Bytes = AlignSize(Bytes, 0x1000ull);

	virtual_buffer_t buf(Bytes);
	uc_mem_read(m_uc, BaseAddress, buf.GetBuffer(), Bytes);
	uc_mem_write(m_uc, MapAddress, buf.GetBuffer(), Bytes);

	m_MemMappings.emplace_back(BaseAddress, MapAddress, Bytes);

	return true;
}

// About: Function for deletion of memory map page
// Param 1: addr to delete, i.e. param 2 addr from `CreateMemMapping`
// Mode: Usermode + Kernelmode
void PeEmulation::DeleteMemMapping(_In_ DWORD_PTR MapAddress)
{
	for (auto itor = m_MemMappings.begin(); itor != m_MemMappings.end();)
	{
		if (itor->mappedva == MapAddress)
		{
			itor = m_MemMappings.erase(itor);
			return;
		}
		else
		{
			itor++;
		}
	}
}

// About: Function for write to memory mapped region
// Param 1: src address
// Param 2: val to write
// Param 3: size of val
// Mode: Usermode + Kernelmode
bool PeEmulation::WriteMemMapping(_In_ DWORD_PTR baseaddress, _In_ DWORD_PTR value, _In_ size_t size)
{
	for (size_t i = 0; i < m_MemMappings.size(); ++i)
	{
		if (baseaddress >= m_MemMappings[i].mappedva && baseaddress < m_MemMappings[i].mappedva + m_MemMappings[i].size)
		{
			auto mapaddress = m_MemMappings[i].baseva + (baseaddress - m_MemMappings[i].mappedva);
			m_MemMappings[i].blocks.emplace_back(mapaddress, value, size);
			return true;
		}
	}
	return false;
}

// About: Function for fulshing of memory map
// Mode: Usermode + Kernelmode
void PeEmulation::FlushMemMapping(_In_ void)
{
	for (size_t i = 0; i < m_MemMappings.size(); ++i)
	{
		for (size_t j = 0; j < m_MemMappings[i].blocks.size(); ++j)
		{
			uc_mem_write(m_uc, m_MemMappings[i].blocks[j].va, &m_MemMappings[i].blocks[j].value, m_MemMappings[i].blocks[j].size);
		}
		m_MemMappings[i].blocks.clear();
	}
}