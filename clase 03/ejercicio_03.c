/* 27/03/2023
ejercicio_03: capturar un texto de varios renglones, lo escribimos y en el mismo leemos su contenido
Usar w+ para escribir y leer el archivo*
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
void sonPolindromos();
int main()
{
    sonPolindromos();
    return 0;
}

void sonPolindromos()
{
    FILE *f;
    char cadena [80];
    f=fopen("texto.txt","w+");
    if (f!=NULL)
    {
        // Escritura del archivo
        printf("indicar fin con ctrl z\n");
        printf("Escriba un texto: ");
        while (gets(cadena)!=NULL)
        {
            fputs(cadena, f); 
            fputc('\n',f);
            printf("Escriba un texto: ");
        } 
        // Lectura del archivo
        rewind(f);
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