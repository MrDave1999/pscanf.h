#include <stdio.h>
#include <pscanf.h>

int main(void)
{
	do
	{
		string str = { NULL };
		strread(&str, "Ingrese una cadena: ");
		printf("\n\n->Data:\n");
		printf("\nString: %s - Length: %d\n", str, str.length);
		pauseprogram();
	} while (1);
	return 0;
}
