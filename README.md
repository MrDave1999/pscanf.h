# PScanf
[![pscanf.h](https://shields.southcla.ws/badge/PSCANF-V2.0-2f2f2f.svg?style=flat-square)](https://github.com/MrDave1999/pscanf.h)

Las características de P-Scanf son:

- Detecta si el dato ingresado por el usuario es el correcto, es decir, si el usuario escribe un caracter y lo que se pide realmente es un entero, dará un error.
- Limpia el búfer del teclado de manera automáticamente, siempre y cuando se use las macros de P-Scanf.
- Tiene un manejo de cadenas de forma segura, así que no se necesita especificar el tamaño del arreglo al momento de pedir información por teclado.
- Cuando el programa termina su ejecución, P-Scanf libera la memoria de forma automática.

# Instalación

Una de las maneras para poder instalar la herramienta P-Scanf, es agregando la carpeta `PSF` en el directorio `include`. Esta carpeta se la encuentra donde se haya instalado el compilador o IDE (Entorno desarrollo integrado).
Por ejemplo, si usamos Dev-C++, se lo debería añadir en la siguiente ruta: C:\Program Files\Dev-Cpp\include\PSF .
Luego nos vamos al archivo fuente y lo incluimos de esta forma:
```C
#include <PSF/pscanf.h>
```
La segunda manera, es agregando la carpeta `PSF` en el directorio donde esté el proyecto y lo incluyes de esta forma:
```C
#include "PSF/pscanf.h"
```

# Macros

- `dataread(_format, _var, ...)` = Permite leer un dato de cualquier tipo desde el búfer de entrada estándar.

- `strread(_var, ...)` = Lee una cadena desde el búfer de entrada estándar. Esta macro hace que la función retorne 1 si llega a suceder un fallo en la asignación de memoria, esto se debe, porqué la cadena se reserva dinámicamente. 

- `pauseprogram()` = Pausa el programa y envía un mensaje diciendo: "Presiona enter para continuar...".

# Uso

**Lectura de un entero:**
```C
#include <stdio.h>
#include <PSF/pscanf.h>

int main(void)
{
	int a;
	dataread("%d", &a, "Ingrese un int: ");
	printf("%d\n", a);
	pauseprogram();
	return 0;
}
```
Si el usuario llegara a escribir un caracter, dará un mensaje de error: "Error: Ingrese un valor entero: ".

**Lectura de una cadena:**
```C
#include <stdio.h>
#include <PSF/pscanf.h>

int main(void)
{
	string name = { NULL }; 
	strread(&name, "Ingrese un string: ");
	printf("String: %s - Length: %d\n", name, name.length);
	pauseprogram();
	return 0;
}
```
Con el miembro "length" se obtiene la longitud de la cadena.

**Recorrido de una cadena:**
```C
#include <stdio.h>
#include <PSF/pscanf.h>

int main(void)
{
	int i;
	string name = { NULL }; 
	strread(&name, "Ingrese un string: ");
	for (i = 0; i != name.length; ++i)
		printf("%c\n", name.s[i]);
	pauseprogram();
	return 0;
}
```
Con el miembro "s" se obtiene el caracter.

**Almacenamiento de múltiples cadenas:**
```C
#include <stdio.h>
#include <stdint.h>
#include <PSF/pscanf.h>
#define MAX_STRINGS (5)

/* La función retorna 0 si se pudo asignar memoria con la macro strread, de lo contrario, devuelve 1. */
uint8_t DataEntry(string* name)
{
	int i;
	for (i = 0; i != MAX_STRINGS; ++i)
	{ /* Es necesario las llaves, la macro strread expande 2 líneas de código. */
		strread(&name[i], "Ingrese un string %d: ", i + 1);
	}
	return 0;
}

void PrintData(string* name)
{
	int i, j;
	for (i = 0; i != MAX_STRINGS; ++i)
		printf("%s\n", name[i]);
	printf("\n");
	for (i = 0; i != MAX_STRINGS; ++i)
	{
		for (j = 0; j != name[i].length; ++j)
			printf("%c", name[i].s[j]);
		printf("\n");
	}
}

int main(void)
{
	string name[MAX_STRINGS] = { NULL };
	if (DataEntry(name)) return 1;
	PrintData(name);
	pauseprogram();
	return 0;
}
```

**Nota:** Es obligatorio inicializar a NULL cada variable de tipo string.

# Créditos

- [MrDave](https://github.com/MrDave1999) 
	- Por el desarrollo de pscanf.h
- [Microsoft Corporation](https://github.com/Microsoft) 
	- Se usó el compilador `cl.exe` para poder compilar los códigos de prueba, de ese modo se comprueba sí no hubo algún error.
