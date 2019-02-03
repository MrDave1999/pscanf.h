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
