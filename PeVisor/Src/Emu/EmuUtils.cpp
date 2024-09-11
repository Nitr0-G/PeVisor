#include "Emu/EmuUtils.hpp"

namespace InternalEmuApi {
	bool EmuWriteNullTermString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::string& str, _In_opt_ bool OnLengthLimit,
		_In_opt_ size_t Length)
	{
		char c;
		uc_err err;
		size_t len = 0;
		while (OnLengthLimit ? len <= Length : len < str.size())
		{
			c = str[len];
			err = uc_mem_write(uc, address + len, &c, sizeof(char));
			if (err != UC_ERR_OK)
				return false;

			len += sizeof(char);

			if (len > 1024 * sizeof(char)) { break; }
		}

		// Write null terminator
		err = uc_mem_write(uc, address + len, &c, sizeof(char));
		if (err != UC_ERR_OK) { return false; }

		return true;
	}

	bool EmuWriteNullTermUnicodeString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::wstring& str, _In_opt_ bool OnLengthLimit,
		_In_opt_ size_t Length)
	{
		wchar_t c;
		uc_err err;
		size_t len = 0;
		while (OnLengthLimit ? len <= Length : len < str.size())
		{
			c = str[len];
			err = uc_mem_write(uc, address + len, &c, sizeof(wchar_t));
			if (err != UC_ERR_OK) { return false; }

			len += sizeof(wchar_t);

			if (len > 1024 * sizeof(wchar_t)) { break; }
		}

		// Write null terminator
		err = uc_mem_write(uc, address + len, &c, sizeof(wchar_t));
		if (err != UC_ERR_OK) { return false; }

		return true;
	}

	bool EmuReadNullTermString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::string& str, _In_opt_ bool OnLengthLimit,
		_In_opt_ size_t Length)
	{
		char c;
		uc_err err;
		size_t len = 0;
		while (1)
		{
			err = uc_mem_read(uc, address + len, &c, sizeof(char));
			if (err != UC_ERR_OK) { return false; }
			if (c != '\0') { str.push_back(c); }
			else { break; }

			if (OnLengthLimit)
			{
				if (Length >= len)
				{
					str.push_back('\0');
					break;
				}
			}

			len += sizeof(char);

			if (len > 1024 * sizeof(char)) { break; }
		}

		return true;
	}

	bool EmuReadNullTermUnicodeString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::wstring& str, _In_opt_ bool OnLengthLimit,
		_In_opt_ size_t Length)
	{
		wchar_t c;
		uc_err err;
		size_t len = 0;
		while (1)
		{
			err = uc_mem_read(uc, address + len, &c, sizeof(wchar_t));
			if (err != UC_ERR_OK) { return false; }
			if (c != L'\0') { str.push_back(c); }
			else { break; }

			if (OnLengthLimit)
			{
				if (Length >= len)
				{
					str.push_back(L'\0');
					break;
				}
			}

			len += sizeof(wchar_t);

			if (len > 1024 * sizeof(wchar_t)) { break; }
		}

		return true;
	}

	void EmuCopyASCIStrs(_In_ uc_engine* uc, _In_ LPSTR Dst, _In_ std::string Src)
	{
		uc_mem_write(uc, (DWORD_PTR)Dst, Src.data(), Src.size());
	}

	void EmuCopyUnicodeStrs(_In_ uc_engine* uc, _In_ LPWSTR EmuAddr, _In_ std::wstring Src)
	{
		uc_mem_write(uc, (DWORD_PTR)EmuAddr, Src.data(), Src.size() * sizeof(wchar_t));
	}

	void EmuCopyBufferFromUc(_In_ uc_engine* uc, _In_ LPVOID MyAddr, _In_ LPVOID EmuAddr, _In_ size_t NumberOfBytes)
	{
		uc_mem_read(uc, (DWORD_PTR)EmuAddr, MyAddr, NumberOfBytes);
	}

	void EmuCopyBufferToUc(_In_ uc_engine* uc, _In_ LPVOID EmuAddr, _In_ LPVOID MyAddr, _In_ size_t NumberOfBytes)
	{
		uc_mem_write(uc, (DWORD_PTR)EmuAddr, MyAddr, NumberOfBytes);
	}

	DWORD_PTR EmuReadReturnAddress(_In_ uc_engine* uc)
	{
		DWORD_PTR rsp;
		uc_reg_read(uc, UC_X86_REG_RSP, &rsp);
		uc_mem_read(uc, rsp, &rsp, 8);

		return rsp;
	}
}