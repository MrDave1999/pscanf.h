#ifndef _INC_PSCANF
#define _INC_PSCANF

#include <stdio.h>
#include <stdint.h>

#ifdef _MSC_VER
	#pragma warning(disable : 4996)
#endif

#define MESSAGE_1 "ERROR: Ingrese un valor flotante (decimal)"
#define MESSAGE_2 "ERROR: Ingrese un valor entero"
#define MESSAGE_3 "ERROR: No se puede ingresar mas de un caracter"

#define debug_buffer(n) while((n = getchar()) != '\n' && n != EOF)

#define MESSAGE_ERROR() \
((!(_format[1] == 'c')) ? (((_format[1] == 'f' || _format[2] == 'f') ? (puts(""MESSAGE_1"")) : (puts(""MESSAGE_2"")))) : (puts(""MESSAGE_3"")))

int32_t _char;

void _datareadEx(const char*const _format, void* const _var)
{
	uint8_t _len = 0, _value = 0;
	int32_t _ch = 0;
	do
	{
		_len = 0;
		_value = 0;
		if (!scanf(_format, _var))
		{
			#ifndef DISABLE_MESSAGE_ERROR
				MESSAGE_ERROR();
			#endif
			debug_buffer(_ch);
			continue;
		}
		if (_format[1] == 'c' && (*(char*)_var) == '\n')
			continue;
		debug_buffer(_ch)
		{
			if (_len < 2 && _ch != ' ')
			{
				++_len;  
				if (_format[1] == 'c' && _len == 1 && *(char*)_var == ' ')
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
			#ifndef DISABLE_MESSAGE_ERROR
				MESSAGE_ERROR();
			#endif
			continue;
		}
		if (_format[1] == 'c' && *(char*)_var == ' ' && _len == 0)
			continue;
		break;
	} while (1);
}

#define dataread(_format, _var, ...) \
	printf(__VA_ARGS__); \
	puts(""); \
	_datareadEx(_format, _var)

void _strreadEx(char*const _Buf, int max)
{
	uint8_t _value = 0;
	int32_t _ch = 0;
	int32_t i;
	max -= 2;
	do
	{
		i = -1;
		debug_buffer(_ch)
		{
			if (_value == 0 && _ch != ' ')
				_value = 1;
			if (i != max)
				_Buf[++i] = _ch;
		}
		if (i == -1 || !_value) continue;
		_Buf[++i] = '\0';
		break;
	}while (1);
}

#define strread(_var, _size, ...) \
	printf(__VA_ARGS__); \
	puts(""); \
	_strreadEx(_var, _size)

#define getchar() \
	_char = getchar(); \
	if (_char != '\n') \
	debug_buffer(_char)

#define pauseprogram() \
	puts("\nPresiona enter para continuar..."); \
	getchar()

#endif /* _INC_PSCANF */
