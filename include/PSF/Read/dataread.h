#ifndef _DATAREAD_H
#define _DATAREAD_H

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

#endif /* _DATAREAD_H */
