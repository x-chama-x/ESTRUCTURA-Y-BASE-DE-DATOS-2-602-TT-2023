/* 27/03/2023
ejercicio_01: “entender el programa”
programa hecho por x_chama_x */

// directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define p printf
#define s scanf
// struct, prototipos 
int main()
{ 
	FILE *archivo;
	char ch; // System("Color 1F")
	char *nombre="texto99.txt";
	if((archivo=fopen(nombre,"w"))==NULL)
	{ 
		p("\n\n***El archivo %s no pudo abrirse ***\n",nombre);
	}
	else
	{
		p("\n\nIngrese caracteres hasta[Enter]");
		while((ch=getchar())!='\n')
		{
			putc(ch,archivo);
			fclose(archivo);
		}
		//system ("Pause");
	}
	return 0;
}
