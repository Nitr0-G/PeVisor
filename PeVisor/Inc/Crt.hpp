#pragma once
#include <unicorn/unicorn.h>

void crt_va_arg_func(uc_engine* uc, uint64_t* ap, void* result, size_t type_size);