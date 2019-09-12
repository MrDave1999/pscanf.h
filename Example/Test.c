#include <stdio.h>
#include <pscanf.h>

int main(void)
{
	do
	{
		int a;
		char b;
		float c;
		double d;
		long double e;
		long long int f;
		dataread("%d", &a, "Ingrese un int: ");
		dataread("%c", &b, "Ingrese un char: ");
		dataread("%f", &c, "Ingrese un float: ");
		dataread("%lf", &d, "Ingrese un double: ");
		dataread("%Lf", &e, "Ingrese un long double: ");
		dataread("%lld", &f, "Ingrese un long long int: ");
		printf("\n\n->Data:\n");
		printf("%d, %c, %f, %f, %f, %lld\n", a, b, c, d, e, f);
		pauseprogram();
	} while (1);
	pauseprogram();
	return 0;
}
 
