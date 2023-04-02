/* 27/03/2023
ejercicio_05: capturar un texto de varios renglones en un archivo y 
determinar la cantidad de palabras por renglon.
programa hecho por x_chama_x */

#include <stdio.h>
#define n 80
void sonPolindromos(); //cargar texto y mostrarlo por pantalla
void palMasLarga();
int main()
{
    sonPolindromos();
    palMasLarga();
    return 0;
}

void sonPolindromos()
{
    FILE *f;
    char cadena [n];
    if ((f=fopen("texto.txt","w+"))!=NULL)
    {
        // crear y escribir en archivo
        printf("indicar fin con ctrl z\n");
        printf("Escriba un texto: ");
        while (gets(cadena)!=NULL)
        {
            fputs(cadena, f); 
            fputc('\n',f);
            printf("Escriba un texto: ");
        }
        rewind(f);
        // mostrar texto del archivo
        printf("\ntexto en el archivo: \n");
        while (fgets(cadena,80,f))
        {
            printf("%s",cadena);
        }
        fclose(f);
    }
    else
    {
        printf("no se pudo abrir el archivo");
    }
}

void palMasLarga()
{
    FILE *f;
    char cadena [n];
    int cnt = 0;

    if ((f=fopen("texto.txt","r"))!=NULL)
    {
        while (fscanf(f, "%s", cadena) == 1)
        {
            cnt++;
        }
        fclose(f);
        printf("\nEl archivo tiene %d palabras.\n", cnt);
    }
    else
    {
        printf("no se pudo abrir el archivo");
    }
}