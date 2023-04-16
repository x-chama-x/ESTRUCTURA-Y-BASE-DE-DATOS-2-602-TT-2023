/* 03/04/2023
ejercicio_06: Basado en el ejercicio 3, 
no dejar ingresar datos repetidos teniendo en cuenta si 
el archivo existe o no antes de la ejecución del programa.
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
	int cod_chof;
	char nom_chof[30];
	int km;
	int rec;
} registro;

void cargar(FILE *);
void mostrar(FILE *);
int buscarCodigo(FILE *,int);
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
    system("cls");
	registro datos;
	int flag=0;
	printf("ingrese 0 para finalizar carga");
	printf("\ningrese el codigo del chofer: ");
	scanf("%d",&datos.cod_chof);
	while (datos.cod_chof!=0)
	{
		if ((buscarCodigo(f,datos.cod_chof))==0) // verifico si cod_chof ya existe  
		{
			system("cls");
			printf("se ha ingresado el mismo codigo\n");
			printf("pulse una tecla para continuar...");
			getch();
			system("cls");
			flag=1;
		}
		else if (flag==0)
		{
			system("cls");
			printf("ingrese el nombre del chofer: ");
			fflush(stdin);
			gets(datos.nom_chof);
			printf("ingrese los km recorridos ");
			scanf("%d",&datos.km);
			datos.rec=200*datos.km;
			fseek(f,0L,SEEK_END);
			fwrite(&datos,sizeof(datos),1,f);
			system("cls");
		}
		flag=0;
		printf("ingrese 0 para finalizar carga");
		printf("\ningrese el codigo del chofer: ");
		scanf("%d",&datos.cod_chof);
		system("cls");
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

int buscarCodigo(FILE *f,int codigoIngresado)
{
    registro datos;
    int flag=1; 
    rewind(f);
    fread(&datos,sizeof(datos),1,f);
	while (!feof(f)&&flag)
	{
        if (datos.cod_chof!=codigoIngresado)
        {
            fread(&datos,sizeof(datos),1,f);
        }
        else
        {
            flag=0;
        }
	}
    return flag;
}