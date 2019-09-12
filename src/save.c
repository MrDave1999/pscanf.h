#include <stdint.h>
#include <stdlib.h>
#include "debug.h"
#include "save.h"

uint8_t createNode(node** const end, size_t* const count)
{
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) return EXIT_FAILURE;
	newNode->sig = *end;
	*end = newNode;
	++(*count);
	return EXIT_SUCCESS;
}

void clearAll(node** const end)
{
	node* aux = *end;
	while (*end != NULL)
	{
		aux = *end;
		*end = (**end).sig;
		free(aux);
	}
}

uint8_t saveStdin(node** const end, size_t* const count)
{
	int32_t ch;
	uint8_t write = 0; /* Para saber si el usuario escribió algo por teclado. */
	do
	{
		DEBUG_BUFFER(ch)
		{
			if (write == 0 && ch != ' ')
				write = 1;
			if (createNode(end, count)) return EXIT_FAILURE;
			(**end).a = ch;
		}
		if (!write)
		{
			clearAll(end);
			*count = 0;
			continue;
		}
		break;
	} while (1);
	return EXIT_SUCCESS;
}

void CopyStdinToString(const node* end, char* const buf, const size_t* const count)
{
	size_t i = *count - 1;
	while (end != NULL)
	{
		*(buf + i) = end->a;
		end = end->sig;
		--i;
	}
	*(buf + *count) = '\0';
}