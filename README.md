# pscanf.h
[![pscanf.h](https://shields.southcla.ws/badge/PSCANF-V2.0-2f2f2f.svg?style=flat-square)](https://github.com/MrDave1999/pscanf.h)

Las características de P-Scanf son:

- Detecta si el dato ingresado por el usuario es el correcto, es decir, si el usuario escribe un caracter y lo que se pide realmente es un entero, dará un error.
- Limpia el búfer del teclado de manera automáticamente, siempre y cuando se use las macros de P-Scanf.
- Tiene un manejo de cadenas de forma segura, así que no se necesita especificar el tamaño del arreglo al momento de pedir información por teclado.
- Libera la memoria automáticamente si llegara a ver un fallo en la asignación de memoria.

# Instalación

- Si usas cl.exe (de Visual Studio) como  compilador de C/C++, debes agregar lo siguiente:

  - La biblioteca estática llamada libpscanf.lib la debes añadir en la carpeta `lib` y se lo encuentra en la siguiente ruta:            	`C:\Program Files\Microsoft Visual Studio 12.0\VC\lib`
	
	Para evitar esta posible advertencia del enlazador: 
	`warning LNK4099: PDB 'libpscanf.pdb' was not found with 'libpscanf.lib' or at 'libpscanf.pdb'; linking object as if no debug info`
	
	Agrega el archivo `libpscanf.pdb` en la misma carpeta donde metas `libpscanf.lib` .
	
	Luego de añadir la biblioteca y el archivo .PDB, abrimos el Visual Studio y nos vamos a la sección de Proyecto -> Propiedades de configuración -> Vinculador -> Entrada -> Dependencias adicionales (en esta opción agregas el nombre de la biblioteca estática con su respectiva extensión .lib) .
	
  - El archivo de cabecera llamado pscanf.h la debes añadir en la carpeta `include` y se lo encuentra en la siguiente ruta:
	`C:\Program Files\Microsoft Visual Studio 12.0\VC\include`
 
Cuando hayas hecho los dos pasos anteriores, procedes a incluir el archivo pscanf.h en el archivo de origen (donde está el main):
```C
#include <pscanf.h>
```
- Si usas Dev-C++ como IDE(Entorno de desarrollo integrado) para compilar códigos de C/C++, debes agregar lo siguiente:

  - La biblioteca estática llamada libpscanf.a la debes añadir en la carpeta `lib` y se lo encuentra en la siguiente ruta: 
  `C:\Program Files\Dev-Cpp\lib`
	
	Luego de añadir la biblioteca, abrimos el Dev-C++ y nos vamos a la sección de Proyecto -> Opciones del proyecto -> Parámetros -> Linker (en esta opción agregas el siguiente comando: -lpscanf) .
	
  - El archivo de cabecera llamado pscanf.h la debes añadir en la carpeta `include` y se lo encuentra en la siguiente ruta:
  `C:\Program Files\Dev-Cpp\include`
  
La biblioteca y el archivo de cabecera lo debes descargar aquí: [PScanf](https://github.com/MrDave1999/pscanf.h/releases/tag/v2.0)
 
# Macros

- `dataread(_format, _var, ...)` = Permite leer un dato de cualquier tipo desde el búfer de entrada estándar.

- `strread(_var, ...)` = Lee una cadena desde el búfer de entrada estándar. Esta macro hace que la función retorne 1 si llega a suceder un fallo en la asignación de memoria, esto se debe, porqué la cadena se reserva dinámicamente. 

# Funciones

- `pause()` = Pausa el programa y envía un mensaje diciendo: "Presiona enter para continuar...".

- `sfree()` = Libera todos los espacios de memoria reservados con la macro `strread`.

# Uso

**Lectura de un entero:**
```C
#include <stdio.h>
#include <pscanf.h>

int main(void)
{
	int a;
	dataread("%d", &a, "Ingrese un int: ");
	printf("%d\n", a);
	return 0;
}
```
Si el usuario llegara a escribir un caracter, dará un mensaje de error: "Error: Ingrese un valor entero: ".

**Lectura de una cadena:**
```C
#include <stdio.h>
#include <pscanf.h>

int main(void)
{
	string name = { NULL }; 
	strread(&name, "Ingrese un string: ");
	printf("String: %s - Length: %d\n", name, name.length);
	sfree();
	pause();
	return 0;
}
```
Con el miembro "length" se obtiene la longitud de la cadena.

**Recorrido de una cadena:**
```C
#include <stdio.h>
#include <pscanf.h>

int main(void)
{
	int i;
	string name = { NULL }; 
	strread(&name, "Ingrese un string: ");
	for (i = 0; i != name.length; ++i)
		printf("%c\n", name.s[i]);
	sfree();
	pause();
	return 0;
}
```
Con el miembro "s" se obtiene el caracter.

**Almacenamiento de múltiples cadenas:**
```C
#include <stdio.h>
#include <stdint.h>
#include <pscanf.h>
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
	sfree();
	pause();
	return 0;
}
```

**Nota:** Es obligatorio inicializar a NULL cada variable de tipo string.

# Créditos

- [MrDave](https://github.com/MrDave1999) 
	- Por el desarrollo de la herramienta P-Scanf
- [Microsoft Corporation](https://github.com/Microsoft) 
	- Se usó el compilador `cl.exe` para poder compilar los códigos de prueba, de ese modo se comprueba sí no hubo algún error.
