#include <stdio.h>
#include <stdint.h>
#include "debug.h"

#ifdef _MSC_VER
	#pragma warning(disable : 4996)
#endif

#define MESSAGE_1 "Error: Ingrese un valor decimal: "
#define MESSAGE_2 "Error: Ingrese un valor entero: "
#define MESSAGE_3 "Error: No se puede ingresar mas de un caracter: "

#define P(message) printf(message) //printf(message + "\n")

#define MESSAGE_ERROR() \
((!(*(_format + 1) == 'c')) ? (((*(_format + 1) == 'f' || *(_format + 2) == 'f' || *(_format + 1) == 'L') ? (P(""MESSAGE_1"")) : (P(""MESSAGE_2"")))) : (P(""MESSAGE_3"")))


void _datareadEx(const char*const _format, void* const _var)
{
	uint8_t _len = 0;
	uint8_t _value = 0;
	int32_t _ch = 0;
	do
	{
		_len = 0;
		_value = 0;
		if (!scanf(_format, _var))
		{
			MESSAGE_ERROR();
			DEBUG_BUFFER(_ch);
			continue;
		}
		/* Para evitar que presionen enter cuando se pida un caracter */
		if (*(_format + 1) == 'c' && (*(char*)_var) == '\n') continue;
		DEBUG_BUFFER(_ch)
		{
			if (_len < 2 && _ch != ' ')
			{
				++_len;
				if (*(_format + 1) == 'c' && _len == 1 && *(char*)_var == ' ')
				{
					*(char*)_var = _ch;
					_value = 1;
				}
			}
		}
		if (_len >= 2)
			_value = 0;
		if (_len >= 1 && !_value)
		{
			MESSAGE_ERROR();
			continue;
		}
		/* Para evitar que escriban únicamente espacios cuando se pida un caracter */
		if (*(_format + 1) == 'c' && *(char*)_var == ' ' && _len == 0) continue;
		break;
	} while (1);
}

void pause()
{
	char a;
	puts("\nPresiona enter para continuar...");
	a = getchar(); 
	if (a != '\n') 
		DEBUG_BUFFER(a);
}