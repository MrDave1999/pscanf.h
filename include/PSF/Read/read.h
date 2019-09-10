#ifndef _READ_H
#define _READ_H

#ifdef _MSC_VER
	#pragma warning(disable : 4996)
#endif

#define MESSAGE_1 "Error: Ingrese un valor decimal: "
#define MESSAGE_2 "Error: Ingrese un valor entero: "
#define MESSAGE_3 "Error: No se puede ingresar mas de un caracter: "

#define P(message) printf(message) //printf(message + "\n")

#define DEBUG_BUFFER(n) while((n = getchar()) != '\n' && n != EOF)

#define MESSAGE_ERROR() \
((!(*(_format + 1) == 'c')) ? (((*(_format + 1) == 'f' || *(_format + 2) == 'f' || *(_format + 1) == 'L') ? (P(""MESSAGE_1"")) : (P(""MESSAGE_2"")))) : (P(""MESSAGE_3"")))

#define dataread(_format, _var, ...) \
	printf(__VA_ARGS__); \
	_datareadEx(_format, _var)

#define strread(_var, ...) \
	printf(__VA_ARGS__); \
	if(_strreadEx(_var)) return EXIT_FAILURE

#define DELETE()									\
	for (int i = countStrings - 1; i != -1; --i)	\
		free(*(buf_p + i));							\
	free(buf_p);									\
	buf_p = NULL

struct _String
{
	char* s;
	size_t length; 
	size_t id;  
};

typedef struct _String string;
int32_t _char;
char** buf_p = NULL;
size_t countStrings;

void _datareadEx(const char*const, void* const);
uint8_t _strreadEx(string* const);
int HookMain();

int main()
{
	DELETE();
	return HookMain();
}

#ifndef _ALS_main
	#define _ALS_main
#else
	#undef main
#endif
#define main HookMain

#endif /* _READ_H */
