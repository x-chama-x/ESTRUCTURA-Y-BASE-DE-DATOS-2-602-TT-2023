/* 03/04/2023
ejercicio_03: Ingresar por teclado, solo calculo la recaudación. La finalización es con cod_chof igual a cero.
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int cod_chof;
	char nom_chof[30];
	int km;
	int rec;
} registro;
void cargar(FILE *);
void mostrar(FILE *);
int main()
{
	FILE *binario;
	char *nombin = "choferes.dat";
	if((binario=fopen(nombin,"rb+"))==NULL)
		binario=fopen(nombin,"wb+");
	cargar(binario);
	mostrar(binario);
	fclose(binario);
	return 0;
}

void cargar(FILE *f)
{
    registro datos;
	printf("ingrese el codigo del chofer: ");
	scanf("%d",&datos.cod_chof);
	while (datos.cod_chof!=0)
	{
		printf("ingrese el nombre del chofer: ");
		fflush(stdin);
		gets(datos.nom_chof);
		printf("ingrese los km recorridos ");
		scanf("%d",&datos.km);
		datos.rec=200*datos.km;
		fseek(f,0L,SEEK_END);
		fwrite(&datos,sizeof(datos),1,f);
		printf("ingrese el codigo del chofer: ");
		scanf("%d",&datos.cod_chof);
	}
	
}

void mostrar(FILE *f)
{
	registro datos;
	rewind(f);
	fread(&datos,sizeof(datos),1,f);
	while (!feof(f))
	{
		printf("%d, ",datos.cod_chof);
		printf("%s, ",datos.nom_chof);
		printf("%d, ",datos.km);
		printf("%d\n",datos.rec);
		fread(&datos,sizeof(datos),1,f);
	}
}