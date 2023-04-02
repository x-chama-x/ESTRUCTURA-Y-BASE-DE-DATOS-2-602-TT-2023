/* 27/03/2023
ejercicio_02: “entender el programa”
programa hecho por x_chama_x */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define p printf
#define s scanf
int main()
{ 
	FILE *archivo;
	char ch,cadena[81];
	char *nombre="texto99.txt";
	if((archivo=fopen(nombre,"w"))==NULL)
	{ 
		p("\n\n***El archivo %s no pudo abrirse ***\n",nombre);
	}
	else
	{
		p("\n\n Este es el contenido del archivo %s caracter a caracter \n\n",nombre);
			while((ch=getc(archivo))!=EOF)
			{
				p("%s",cadena);
			}
		p("\n\n Este es el contenido del archivo %s renglon a renglon \n\n",nombre);
		rewind(archivo);
		while(fgets(cadena,81,archivo));
		p("\n\n **Fin**\n\n");
		getch();
		fclose(archivo);
	}
	return 0;
}