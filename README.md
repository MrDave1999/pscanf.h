# pscanf.h

Con este archivo de cabecera podrás validar el dato ingresado por el usuario. En algunas ocasiones cuando tenemos un programa con menú de opciones y pedimos algún dato, por ejemplo un entero, el usuario toma la decisión de que tipo de dato quiere ingresar y sí llegara escribir una cadena, lo más probable es que haya un resultado inesperado en el programa. 
Por esa razón, se creó `pscanf.h` para darle solución a este problema.

# Instalación

Hay dos formas de instalar `pscanf.h`.
1. Podrías agregar el archivo de cabecera en la carpeta `include`, la que viene por defecto en el IDE (entorno de desarrollo integrado) y luego de eso, debes incluir el fichero de esta forma:
```C
#include <pscanf.h>
```
2. La siguiente manera es agregando `pscanf.h` en la carpeta dónde esté el programa fuente situado y luego deberás incluir el fichero de esta forma:
```C
#include "pscanf.h"
```

# Macros

- `dataread` = Permite leer un dato de cualquier tipo desde el búfer de entrada estándar.

- `strread` = Lee una cadena desde el búfer de entrada estándar. Además de eso, evita el desbordamiento de búfer.

- `pauseprogram` = Pausa el programa y envía un mensaje diciendo: "Presiona enter para continuar...".

- `DISABLE_MESSAGE_ERROR` = Desactiva los mensajes de error. Lo debes agregar antes de incluir `pscanf.h`.
```C
#define DISABLE_MESSAGE_ERROR
#include "pscanf.h"
```

# Uso

- Ejemplo 1:

Pedir un dato entero al usuario.
```C
#include "pscanf.h"
int main(void)
{
	int x;
	dataread("%d", &x, "Ingrese un entero:");
	pauseprogram();
	return 0;
}
```

- Ejemplo 2:

Pedir un dato flotante al usuario.
```C
#include "pscanf.h"
int main(void)
{
	float x;
	dataread("%f", &x, "Ingrese un decimal:");
	pauseprogram();
	return 0;
}
```

Sí el usuario llegara escribir esto: `hhhhhh` o `24hhhh` en vez de un "entero" o un "flotante", `dataread` pausará el programa y manda un mensaje de error.

- Ejemplo 3:

Pedir un caracter al usuario.
Sí el usuario ingresa más de un caracter, `dataread` pausa el programa y manda un mensaje de error.
```C
#include "pscanf.h"
int main(void)
{
	char x;
	dataread("%c", &x, "Ingrese un caracter:");
	pauseprogram();
	return 0;
}
```

- Ejemplo 4:

Pedir una cadena al usuario.
Sí la cantidad máxima de caracteres es 24. `strread` sólo va a leer 22 caracteres y asigna un caracter nulo al búfer de destino (en este caso es el array `x`).
```C
#include "pscanf.h"
int main(void)
{
	char x[24];
	strread(x, 24, "Ingrese una cadena:");
	pauseprogram();
	return 0;
}
```

# Código de Prueba
```C
#include "pscanf.h"

int main(void)
{
	do
	{
		int x;
		char y;
		char z[24];
		float p;
		dataread("%d", &x, "Ingrese un entero:");
		dataread("%c", &y, "Ingrese un caracter:");
		strread(z, 24, "Ingrese una cadena:");
		dataread("%f", &p, "Ingrese un decimal:");
		printf("\n\n->Data:\n");
		printf("X: %d\n", x);
		printf("Y: %c\n", y);
		printf("Z: %s\n", z);
		printf("P: %.3f\n", p);
		pauseprogram();
	} while (1);
	return 0;
}
```

# Resultado en Pantalla
[![Resultado en Pantalla](https://i.imgur.com/uFshspC.png)](https://github.com/MrDave1999)

# Créditos

- [MrDave](https://github.com/MrDave1999) 
	- Por el desarrollo de pscanf.h
- [Microsoft Corporation](https://github.com/Microsoft) 
	- Se usó el compilador `cl.exe` para poder compilar los códigos de prueba, de ese modo se comprueba sí no hubo algún error.
