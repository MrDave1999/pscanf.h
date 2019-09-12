#include <stdlib.h>
#include <stdint.h>
#include "debug.h"
#include "pscanf.h"
#include "save.h"

struct _Buffer
{
	char** buf;
	size_t countStrings;
};

struct _Buffer b;

uint8_t _strreadEx(string* const ptr)
{
	char* ptrtemp;
	node* end = NULL;
	size_t count = 0; /* Cantidad de caracteres ingresados por teclado */
	int32_t ch;
	if (saveStdin(&end, &count))
	{
		printf("Error: No se pudo asignar memoria.\n");
		clearAll(&end);
		/* Para pausar el programa. */
		DEBUG_BUFFER(ch);
		sfree();
		getchar();
		return EXIT_FAILURE;
	}
	if (ptr->s == NULL)
	{
		ptr->id = b.countStrings;
		++b.countStrings;
		/* Crea el string de X elementos leídos por teclado. */
		ptr->s = (char*)malloc((count + 1) * sizeof(char));
		if (ptr->s == NULL)
		{
			puts("Error: No se pudo reservar memoria.");
			clearAll(&end);
			sfree();
			getchar();
			return EXIT_FAILURE;
		}
		CopyStdinToString(end, ptr->s, &count);
		clearAll(&end);
		ptrtemp = (char*)b.buf;
		/* Crea un búfer de punteros para tener almacenada la dirección base de cada string */
		b.buf = (char**)realloc(b.buf, b.countStrings * sizeof(char*));
		if (b.buf == NULL)
		{
			puts("Error: No se pudo reservar memoria.");
			b.buf = (char**)ptrtemp;
			sfree();
			getchar();
			return EXIT_FAILURE;
		}
		b.buf[ptr->id] = ptr->s;
	}
	else
	{
		ptrtemp = b.buf[ptr->id];
		/* Re-dimensiona el string con los caracteres actualizados */
		b.buf[ptr->id] = (char*)realloc(ptrtemp, (count + 1) * sizeof(char));
		if (b.buf[ptr->id] == NULL)
		{
			puts("Error: No se pudo reservar memoria.");
			clearAll(&end);
			b.buf[ptr->id] = ptrtemp;
			sfree();
			getchar();
			return EXIT_FAILURE;
		}
		ptr->s = b.buf[ptr->id];
		CopyStdinToString(end, ptr->s, &count);
		clearAll(&end);
	}
	ptr->length = count;
	return EXIT_SUCCESS;
}

void sfree()
{
	for (int i = b.countStrings - 1; i != -1; --i)	
		free(b.buf[i]);							
	free(b.buf);								
	b.buf = NULL;
}