#ifndef _STRREAD_H
#define _STRREAD_H

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
		getchar();
		return EXIT_FAILURE;
	}
	if (ptr->s == NULL)
	{
		ptr->id = countStrings;
		++countStrings;
		/* Crea el string de X elementos leídos por teclado. */
		ptr->s = (char*)malloc((count + 1) * sizeof(char));
		if (ptr->s == NULL)
		{
			puts("Error: No se pudo reservar memoria.");
			clearAll(&end);
			getchar();
			return EXIT_FAILURE;
		}
		CopyStdinToString(end, ptr->s, &count);
		clearAll(&end);
		ptrtemp = (char*)buf_p;
		/* Crea un búfer de punteros para tener almacenada la dirección base de cada string */
		buf_p = (char**)realloc(buf_p, countStrings* sizeof(char*));
		if (buf_p == NULL)
		{
			puts("Error: No se pudo reservar memoria.");
			buf_p = (char**)ptrtemp;
			getchar();
			return EXIT_FAILURE;
		}
		*(buf_p + ptr->id) = ptr->s;
	}
	else
	{
		ptrtemp = *(buf_p + ptr->id);
		/* Re-dimensiona el string con los caracteres actualizados */
		*(buf_p + ptr->id) = (char*)realloc(ptrtemp, (count + 1) * sizeof(char));
		if (*(buf_p + ptr->id) == NULL)
		{
			puts("Error: No se pudo reservar memoria.");
			clearAll(&end);
			*(buf_p + ptr->id) = ptrtemp;
			getchar();
			return EXIT_FAILURE;
		}
		ptr->s = *(buf_p + ptr->id);
		CopyStdinToString(end, ptr->s, &count);
		clearAll(&end);
	}
	ptr->length = count;
	return EXIT_SUCCESS;
}
 
#endif /* _STRREAD_H */
