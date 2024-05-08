#ifndef UNICORN_HOOKS
#define UNICORN_HOOKS

#include "UCPE.hpp"

namespace ucHooks {
	void HookCode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
	void HookIntr(uc_engine* uc, int exception, void* user_data);
}

#endif