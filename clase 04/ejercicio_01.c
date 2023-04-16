/* 03/04/2023
ejercicio_01: Utilizar la función strtok y armar una funcion que se 
llame void sacar() que lo que recibe es una cadena de texto 
del archivo “textoParaSeparar.txt” 
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 80
void sacar(char[]);
int main ()
{
    char cadena[n];
    FILE *f;
    if ((f=fopen("textoParaSeparar.txt","r"))!=NULL)
    {
        while (fgets(cadena,n,f)!=NULL)
        {
            sacar(cadena);
        }
        fclose(f);
    }else
    {
        printf("no se pudo abrir el archivo");
    }
    return 0;
}

void sacar(char cadena[])
{
    char *pri,*seg,*terc;
    pri=strtok(cadena,",");
    printf("%3d ",atoi(pri));
    seg=strtok(NULL,",");
    printf("%-20s",seg);
    terc=strtok(NULL,",");
    printf("%d\n",atoi(terc));
}