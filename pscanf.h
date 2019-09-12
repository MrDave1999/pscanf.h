/*
	MIT License

	Copyright (c) 2019 David Román

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef _PSCANF_H
#define _PSCANF_H

#include <stdio.h>
#include <stdint.h>

#define dataread(_format, _var, ...) \
	printf(__VA_ARGS__); \
	_datareadEx(_format, _var)

#define strread(_var, ...) \
	printf(__VA_ARGS__); \
	if(_strreadEx(_var)) return 1

struct _String
{
	char* s;
	size_t length;
	size_t id;
};

typedef struct _String string;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

uint8_t _strreadEx(string* const);
void _datareadEx(const char*const, void* const);
void sfree(void);
void pause(void);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _PSCANF_H */
