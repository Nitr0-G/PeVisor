#include "Crt.hpp"

void crt_va_arg_func(uc_engine* uc, uint64_t* ap, void* result, size_t type_size) {
	if (type_size > sizeof(__int64) || (type_size & (type_size - 1)) != 0) {
		// Если размер больше 8 байт или не кратен 8, считаем данные как двойной указатель
		char* buffer = (char*)malloc(type_size); // Выделяем память под буфер
		uc_err err = uc_mem_read(uc, ((*ap += sizeof(__int64)) - sizeof(__int64)), buffer, type_size);
		if (err != UC_ERR_OK) {
			// Обработка ошибки чтения
			free(buffer);
			return;
		}
		memcpy(result, buffer, type_size); // Копируем данные из буфера в результат
		free(buffer);


	}
	else {
		// Для типов размером до 8 байт считываем напрямую
		uc_err err = uc_mem_read(uc, ((*ap += sizeof(__int64)) - sizeof(__int64)), result, type_size);
		if (err != UC_ERR_OK) {
			// Обработка ошибки чтения
			return;
		}
	}
}