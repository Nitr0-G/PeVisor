#include "UCPE.hpp"
#include "EmuApiFuncs.hpp"
#include "Trace.hpp"
#include <fstream>
extern std::ostream* outs;

namespace ucHooks {

	std::vector<std::string> Instrs;

	void HookSySCall(uc_engine* uc, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		std::stringstream region;

		DWORD_PTR Rip = 0;
		uc_reg_read(uc, UC_X86_REG_RIP, &Rip);
		ctx->FindAddressInRegion(Rip, region);
		*outs << "Syscall at " << region.str() << "\n";
	}

	void HookCpuid(uc_engine* uc, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;
		CPUID_REGS Regs{};

		uint32_t eax;
		uc_reg_read(uc, UC_X86_REG_EAX, &eax);

		std::string szCPUID_FUNCTION;

		// Check the 'AuthenticAMD' vendor name:
		__cpuid(Regs.Raw, CPUID::Generic::CPUID_MAXIMUM_FUNCTION_NUMBER_AND_VENDOR_ID);
		if (Regs.Regs.Ebx != AmdEnc::AEbx || Regs.Regs.Edx != AmdEnc::AEdx || Regs.Regs.Ecx != AmdEnc::AEcx)
		{
			Regs = {0};

			__cpuid(Regs.Raw, eax);
			switch (eax)
			{
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_MAXIMUM_FUNCTION_NUMBER_AND_VENDOR_ID:
				szCPUID_FUNCTION = "CPUID_MAXIMUM_FUNCTION_NUMBER_AND_VENDOR_ID";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_FEATURE_INFORMATION:
				szCPUID_FUNCTION = "CPUID_FEATURE_INFORMATION";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_MONITOR_MWAIT_PARAMETERS:
				szCPUID_FUNCTION = "CPUID_MONITOR_MWAIT_PARAMETERS";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_THERMAL_POWER_MANAGEMENT:
				szCPUID_FUNCTION = "CPUID_THERMAL_POWER_MANAGEMENT";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_STRUCTURED_EXTENDED_FEATURE_ENUMERATION:
				szCPUID_FUNCTION = "CPUID_STRUCTURED_EXTENDED_FEATURE_ENUMERATION";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_PROCESSOR_EXTENDED_STATE_ENUMERATION:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_EXTENDED_STATE_ENUMERATION";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_MAXIMUM_EXTENDED_FUNCTION_NUMBER_AND_VENDOR_ID:
				szCPUID_FUNCTION = "CPUID_MAXIMUM_EXTENDED_FUNCTION_NUMBER_AND_VENDOR_ID";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_EXTENDED_FEATURE_INFORMATION:
				szCPUID_FUNCTION = "CPUID_EXTENDED_FEATURE_INFORMATION";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_PROCESSOR_BRAND_STRING_0:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_BRAND_STRING_0";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_PROCESSOR_BRAND_STRING_1:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_BRAND_STRING_1";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_PROCESSOR_BRAND_STRING_2:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_BRAND_STRING_2";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_L1_AND_TLB:
				szCPUID_FUNCTION = "CPUID_L1_AND_TLB";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_L2_L3_TLB:
				szCPUID_FUNCTION = "CPUID_L2_L3_TLB";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_POWER_MANAGEMENT_AND_RAS_CAPABILITIES:
				szCPUID_FUNCTION = "CPUID_POWER_MANAGEMENT_AND_RAS_CAPABILITIES";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_CAPACITY_AND_EXTENDED_FEATURES:
				szCPUID_FUNCTION = "CPUID_CAPACITY_AND_EXTENDED_FEATURES";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_SVM_FEATURES:
				szCPUID_FUNCTION = "CPUID_SVM_FEATURES";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_TLB_CHARACTERISTICS_FOR_1GB_PAGES:
				szCPUID_FUNCTION = "CPUID_TLB_CHARACTERISTICS_FOR_1GB_PAGES";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_INSTRUCTION_OPTIMIZATIONS:
				szCPUID_FUNCTION = "CPUID_INSTRUCTION_OPTIMIZATIONS";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_INSTRUCTION_BASED_SAMPLING_CAPABILITIES:
				szCPUID_FUNCTION = "CPUID_INSTRUCTION_BASED_SAMPLING_CAPABILITIES";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_LIGHTWEIGHT_PROFILING_CAPABILITIES:
				szCPUID_FUNCTION = "CPUID_LIGHTWEIGHT_PROFILING_CAPABILITIES";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_CACHE_TOPOLOGY_INFORMATION:
				szCPUID_FUNCTION = "CPUID_CACHE_TOPOLOGY_INFORMATION";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_PROCESSOR_TOPOLOGY_INFORMATION:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_TOPOLOGY_INFORMATION";
				break;
			case CPUID::AMD::CPUID_FUNCTIONS::CPUID_ENCRYPTED_MEMORY_CAPABILITIES:
				szCPUID_FUNCTION = "CPUID_ENCRYPTED_MEMORY_CAPABILITIES";
				break;
			}
		}
		else
		{
			Regs = {0};

			__cpuid(Regs.Raw, eax);
			switch (eax)
			{
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_MAXIMUM_FUNCTION_NUMBER_AND_VENDOR_ID:
				szCPUID_FUNCTION = "CPUID_MAXIMUM_FUNCTION_NUMBER_AND_VENDOR_ID";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_FEATURE_INFORMATION:
				szCPUID_FUNCTION = "CPUID_FEATURE_INFORMATION";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_MONITOR_MWAIT_PARAMETERS:
				szCPUID_FUNCTION = "CPUID_MONITOR_MWAIT_PARAMETERS";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_THERMAL_POWER_MANAGEMENT:
				szCPUID_FUNCTION = "CPUID_THERMAL_POWER_MANAGEMENT";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_STRUCTURED_EXTENDED_FEATURE_ENUMERATION:
				szCPUID_FUNCTION = "CPUID_STRUCTURED_EXTENDED_FEATURE_ENUMERATION";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_MAXIMUM_EXTENDED_FUNCTION_NUMBER_AND_VENDOR_ID:
				szCPUID_FUNCTION = "CPUID_MAXIMUM_EXTENDED_FUNCTION_NUMBER_AND_VENDOR_ID";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_EXTENDED_FEATURE_INFORMATION:
				szCPUID_FUNCTION = "CPUID_EXTENDED_FEATURE_INFORMATION";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_PROCESSOR_BRAND_STRING_0:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_BRAND_STRING_0";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_PROCESSOR_BRAND_STRING_1:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_BRAND_STRING_1";
				break;
			case CPUID::Generic::CPUID_FUNCTIONS::CPUID_PROCESSOR_BRAND_STRING_2:
				szCPUID_FUNCTION = "CPUID_PROCESSOR_BRAND_STRING_2";
				break;
			}
		}

		DWORD_PTR Rax = Regs.Regs.Eax, Rbx = Regs.Regs.Ebx, Rcx = Regs.Regs.Ecx, Rdx = Regs.Regs.Edx;
		uc_reg_write(uc, UC_X86_REG_RAX, &Rax);
		uc_reg_write(uc, UC_X86_REG_RBX, &Rbx);
		uc_reg_write(uc, UC_X86_REG_RCX, &Rcx);
		uc_reg_write(uc, UC_X86_REG_RDX, &Rdx);

		std::stringstream region;

		DWORD_PTR Rip = 0;
		uc_reg_read(uc, UC_X86_REG_RIP, &Rip);
		ctx->FindAddressInRegion(Rip, region);

		std::cout << "CPUID at " << region.str() << " with cpuid function: " << szCPUID_FUNCTION << "\n";
		std::cout << "EAX: " << Regs.Regs.Eax << " EBX: " << Regs.Regs.Ebx << " ECX: " << Regs.Regs.Ecx
			<< " EDX: " << Regs.Regs.Edx << "\n";
	}

	void HookCode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		/*PeEmulation* ctx = (PeEmulation*)user_data;

		ZydisDecoder DecoderMinimal{ ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64, ZYDIS_DECODER_MODE_MINIMAL };
		ZydisDecodedInstruction Instruction{};
		ZydisDecodedOperand Operands[ZYDIS_MAX_OPERAND_COUNT];

		ZydisFormatter Formatter;
		ZydisFormatterInit(&Formatter, ZYDIS_FORMATTER_STYLE_INTEL);

		ZydisDecoderDecodeFull(
			&DecoderMinimal,
			(const void*)address,
			ZYDIS_MAX_INSTRUCTION_LENGTH,
			&Instruction,
			Operands);

		std::stringstream region;
		ctx->FindAddressInRegion(address, region);

		char buffer[512]{};
		ZydisFormatterFormatInstruction(&Formatter, &Instruction, Operands,
			Instruction.operand_count_visible, buffer, sizeof(buffer), address, ZYAN_NULL);

		*outs << region.str() << ": " << buffer << "\n";*/
		//Instrs.push_back(buffer);

		//EmuReadReturnAddress(uc);
		//DWORD_PTR RCX = EmuReadReturnAddress(uc);
		////uc_reg_read(uc, UC_X86_REG_RSP, &RCX);
		//std::stringstream szR8;
		//if (ctx->FindAddressInRegion(RCX, szR8))
		//{
		//	*outs << "RCX: " << szR8.str() << "\n";
		//}
		//else
		//{
		//	*outs << "RCX: " << RCX << "\n";
		//}

		//DWORD_PTR Val = 0;
		//uc_mem_read(uc, (DWORD_PTR)(ctx->m_HeapBase + 0x1838), &Val, sizeof(Val));
		//*outs << "Val: " << Val << "\n";

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
			CONTEXT CpuContext{};

			ctx->RtlpCaptureContext(&CpuContext);

			EXCEPTION_RECORD excprec{};
			DWORD_PTR Rip = 0;
			uc_reg_read(uc, UC_X86_REG_RIP, &Rip);
			excprec.ExceptionCode = EXCEPTION_BREAKPOINT;
			excprec.ExceptionFlags = 0;
			excprec.ExceptionAddress = (PVOID)Rip;

			BOOL A = ctx->RtlpDispatchException(&excprec, &CpuContext);

			ctx->RtlpRestoreContext(&CpuContext, &excprec);
		}
		else
		{
			ctx->m_LastException = STATUS_SUCCESS;
		}

		DWORD_PTR RIP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &RIP);
		std::stringstream szR8;
		if (ctx->FindAddressInRegion(RIP, szR8))
		{
			*outs << "RIP: " << szR8.str() << "\n";
		}
		else
		{
			*outs << "RIP: " << RIP << "\n";
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

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region, false, false, true))
			{
				*outs << "UC_MEM_READ on region " << region.str() << "\n";

				uint64_t rip;
				uc_reg_read(uc, UC_X86_REG_RIP, &rip);
				region.str("");
				if (ctx->FindAddressInRegion(rip, region))
					*outs << "UC_MEM_READ rip at " << region.str() << "\n";
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

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region, false, false, true))
			{
				*outs << "UC_MEM_WRITE on region " << region.str() << "\n";

				uint64_t rip;
				uc_reg_read(uc, UC_X86_REG_RIP, &rip);
				region.str("");
				if (ctx->FindAddressInRegion(rip, region))
					*outs << "UC_MEM_WRITE rip at " << region.str() << "\n";
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

		std::ofstream file("output.txt");
		if (!file.is_open()) {
			std::cerr << "Failed to open file for writing." << std::endl;
			return 1;
		}

		for (const auto& instr : Instrs) {
			file << instr << "\n";
		}

		file.close();

		switch (type) {
		case UC_MEM_FETCH_PROT: {
			uint64_t rip;
			uc_reg_read(uc, UC_X86_REG_RIP, &rip);

			std::stringstream region;
			if (ctx->FindAddressInRegion(address, region))
				*outs << "UC_MEM_FETCH_PROT from " << region.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_PROT from " << std::hex << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_FETCH_PROT rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_PROT rip at " << std::hex << rip << "\n";

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
				*outs << "UC_MEM_WRITE_PROT from " << std::hex << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_WRITE_PROT rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_WRITE_PROT rip at " << std::hex << rip << "\n";

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
				*outs << "UC_MEM_FETCH_UNMAPPED from " << std::hex << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_FETCH_UNMAPPED rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_FETCH_UNMAPPED rip at " << std::hex << rip << "\n";

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
				*outs << "UC_MEM_READ_UNMAPPED from " << std::hex << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_READ_UNMAPPED rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_READ_UNMAPPED rip at " << std::hex << rip << "\n";

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
				*outs << "UC_MEM_WRITE_UNMAPPED from " << std::hex << address << "\n";

			std::stringstream region2;
			if (ctx->FindAddressInRegion(rip, region2))
				*outs << "UC_MEM_WRITE_UNMAPPED rip at " << region2.str() << "\n";
			else
				*outs << "UC_MEM_WRITE_UNMAPPED rip at " << std::hex << rip << "\n";

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