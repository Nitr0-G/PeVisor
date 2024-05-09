#include "UCPE.hpp"
#include "EmuApiFuncs.hpp"
#include "Trace.hpp"

extern std::ostream* outs;

namespace ucHooks {

	void HookCode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		ZydisDecoder DecoderMinimal{ ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64, ZYDIS_DECODER_MODE_MINIMAL };
		ZydisDecodedInstruction Instruction{};
		ZydisDecodedOperand Operands[ZYDIS_MAX_OPERAND_COUNT];

		ZydisDecoderDecodeFull(
			&DecoderMinimal,
			(const void*)address,
			ZYDIS_MAX_INSTRUCTION_LENGTH,
			&Instruction,
			Operands);

		//if (Instruction.mnemonic == ZYDIS_MNEMONIC_RDTSC)
		//{
		//	std::stringstream region;
		//	DWORD_PTR Rax = __rdtsc();
		//	DWORD_PTR Rip = address + size;
		//	Rax = 0;
		//	DWORD_PTR Rdx = 0;
		//	uc_reg_write(uc, UC_X86_REG_RAX, &Rax);
		//	uc_reg_write(uc, UC_X86_REG_RDX, &Rdx);
		//	uc_reg_write(uc, UC_X86_REG_RIP, &Rip);
		//	if (ctx->FindAddressInRegion(address, region))
		//	{
		//		*outs << "RDTSC at " << region.str() << "\n";
		//	}
		//	else
		//	{
		//		*outs << "RDTSC at " << address << "\n";
		//	}
		//}
	}
	
	void HookIntr(uc_engine* uc, int exception, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;
		*outs << "Exception " << std::hex << exception << "\n";

		if (exception == EXCP01_DB)
		{
			ctx->m_LastException = STATUS_SINGLE_STEP;

			DWORD_PTR rflags = 0;
			uc_reg_read(uc, UC_X86_REG_RFLAGS, &rflags);

			rflags &= ~(1 << 8);
			uc_reg_write(uc, UC_X86_REG_RFLAGS, &rflags);

			CONTEXT CpuContext{};

			ctx->RtlpCaptureContext(&CpuContext);

			EXCEPTION_RECORD excprec{};
			DWORD_PTR Rip = 0;
			uc_reg_read(uc, UC_X86_REG_RIP, &Rip);
			excprec.ExceptionCode = EXCEPTION_SINGLE_STEP;
			excprec.ExceptionFlags = 0;
			excprec.ExceptionAddress = (PVOID)Rip;

			BOOL A = ctx->RtlpDispatchException(&excprec, &CpuContext);

			ctx->RtlpRestoreContext(&CpuContext, &excprec);
		}
		else if (exception == EXCP03_INT3)
		{
			ctx->m_LastException = STATUS_BREAKPOINT;
		}
		else
		{
			ctx->m_LastException = STATUS_SUCCESS;
		}
		uc_emu_stop(uc);
	}

	void HookRwx(uc_engine* uc, uc_mem_type type,
		DWORD_PTR address, int size, INT_PTR value, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		switch (type) {
		case UC_MEM_READ: {
			if (ctx->m_BoundCheck)
			{
				std::stringstream region;
				if (!ctx->FindAddressInRegion(address, region))
				{
					*outs << "UC_MEM_READ out of region\n";

					uint64_t rip;
					uc_reg_read(uc, UC_X86_REG_RIP, &rip);
					if (ctx->FindAddressInRegion(rip, region))
						*outs << "UC_MEM_READ rip at " << region.str() << "\n";

					uc_emu_stop(uc);
				}
			}

			break;
		}
		case UC_MEM_WRITE: {
			if (ctx->m_BoundCheck)
			{
				std::stringstream region;
				if (!ctx->FindAddressInRegion(address, region))
				{
					*outs << "UC_MEM_WRITE out of region\n";

					uint64_t rip;
					uc_reg_read(uc, UC_X86_REG_RIP, &rip);
					if (ctx->FindAddressInRegion(rip, region))
						*outs << "UC_MEM_WRITE rip at " << region.str() << "\n";

					uc_emu_stop(uc);
				}
			}
			if (ctx->WriteMemMapping(address, value, size))
			{
				//*outs << "write to mapping address " << address << "\n";
			}

			break;
		}
		case UC_MEM_FETCH: {


			break;
		}
		}
	}

	bool HookInvalidRwx(uc_engine* uc, uc_mem_type type,
		DWORD_PTR address, int size, INT_PTR value, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		switch (type) {
		case UC_MEM_FETCH_PROT: {
			uint64_t rip;
			uc_reg_read(uc, UC_X86_REG_RIP, &rip);

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region))
				*outs << "UC_MEM_FETCH_PROT from " << region.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_PROT from " << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_FETCH_PROT rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_PROT rip at " << rip << "\n";

			uc_emu_stop(uc);
			break;
		}
		case UC_MEM_WRITE_PROT: {
			uint64_t rip;
			uc_reg_read(uc, UC_X86_REG_RIP, &rip);

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region))
				*outs << "UC_MEM_WRITE_PROT from " << region.str() << "\n";
			else
				*outs << "UC_MEM_WRITE_PROT from " << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_WRITE_PROT rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_WRITE_PROT rip at " << rip << "\n";

			uc_emu_stop(uc);
			break;
		}
		case UC_MEM_FETCH_UNMAPPED: {
			uint64_t rip;
			uc_reg_read(uc, UC_X86_REG_RIP, &rip);

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region))
				*outs << "UC_MEM_FETCH_UNMAPPED from " << region.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_UNMAPPED from " << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_FETCH_UNMAPPED rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_UNMAPPED rip at " << rip << "\n";

			uc_emu_stop(uc);
			break;
		}
		case UC_MEM_READ_UNMAPPED: {
			uint64_t rip;
			uc_reg_read(uc, UC_X86_REG_RIP, &rip);

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region))
				*outs << "UC_MEM_READ_UNMAPPED from " << region.str() << "\n";
			else
				*outs << "UC_MEM_READ_UNMAPPED from " << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_READ_UNMAPPED rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_READ_UNMAPPED rip at " << rip << "\n";

			uc_emu_stop(uc);
			break;
		}
		case UC_MEM_WRITE_UNMAPPED: {
			uint64_t rip;
			uc_reg_read(uc, UC_X86_REG_RIP, &rip);

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region))
				*outs << "UC_MEM_WRITE_UNMAPPED from " << region.str() << "\n";
			else
				*outs << "UC_MEM_WRITE_UNMAPPED from " << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_WRITE_UNMAPPED rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_WRITE_UNMAPPED rip at " << rip << "\n";

			uc_emu_stop(uc);
			break;
		}
		}
		return false;
	}

	void EmuUnknownAPI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		std::wstring DllName;
		PFakeAPI api = nullptr;

		DWORD_PTR currentModule = 0;
		ctx->FindModuleByAddress(address, currentModule);

		if (currentModule != ctx->m_LastRipModule)
		{
			if (ctx->m_LastRipModule == ctx->m_ImageBase)
			{
				if (ctx->FindAPIByAddress(address, DllName, &api))
				{
					if (!api->EmuCallback)
					{
						std::string aDllName;
						UnicodeToANSI(DllName, aDllName);
						*outs << "API emulation callback not registered: " << aDllName << "!" << api->ProcedureName << "\n";
						auto retaddr = EmuReadReturnAddress(uc);
						if (retaddr >= ctx->m_ImageBase && retaddr < ctx->m_ImageEnd)
							*outs << "called from imagebase+0x" << std::hex << (ULONG)(retaddr - ctx->m_ImageBase) << "\n";
						uc_emu_stop(uc);
					}
					else
					{
						void(*callback)(uc_engine * uc, DWORD_PTR address, size_t size, void* user_data)
							= (decltype(callback))api->EmuCallback;

						callback(uc, address, size, user_data);
					}
				}
				else
				{
					*outs << "unknown API called\n";
					auto retaddr = EmuReadReturnAddress(uc);
					if (retaddr >= ctx->m_ImageBase && retaddr < ctx->m_ImageEnd)
						*outs << "called from imagebase+0x" << std::hex << (ULONG)(retaddr - ctx->m_ImageBase) << "\n";
					uc_emu_stop(uc);
				}
			}
			ctx->m_LastRipModule = currentModule;
		}
		else if (currentModule != ctx->m_ImageBase)
		{
			if (ctx->FindAPIByAddress(address, DllName, &api))
			{
				_CrtDbgBreak();
			}
		}

		if (currentModule == ctx->m_ImageBase && ctx->m_IsPacked && !ctx->m_ImageRealEntry)
		{
			PFakeSection section = nullptr;
			if (ctx->FindSectionByAddress(address, &section) && !section->IsUnknownSection)
			{
				ctx->m_ImageRealEntry = address;
			}
		}
	}
}