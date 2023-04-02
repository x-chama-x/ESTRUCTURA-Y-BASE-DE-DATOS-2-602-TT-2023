/* 27/03/2023
ejercicio_04: capturar un texto de varios renglones en un archivo y copiarlo 
en un segundo archivo. Para ello utilizar funciones. 
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
void cargar (FILE *); // cargar el texto en un primer archivo
void mostrar (FILE *); // mostrar
void grabar(FILE *,FILE *); // grabar el texto del archivo 1 en el archivo 2
int main()
{
    FILE f,f2;
    cargar(&f);
    printf("texto del archivo original: \n");
    mostrar(&f);
    grabar(&f,&f2);
    printf("texto del archivo copia: \n");
    mostrar(&f2);
    return 0;
}

void cargar(FILE *f)
{
    char cadena [80];
    if ((f=fopen("texto.txt","w"))!=NULL)
    {
        printf("indicar fin con ctrl z\n");
        printf("Escriba un texto: ");
        while (gets(cadena)!=NULL)
        {
            fputs(cadena, f); 
            fputc('\n',f);
            printf("Escriba un texto: ");
        }
        fclose(f);
    }
    else
    {
        printf("no se pudo abrir el archivo");
    }
}

void mostrar (FILE *f)
{
    char cadena [80];
    if ((f=fopen("texto.txt","r"))!=NULL||(f=fopen("texto2.txt","r"))!=NULL)
    {
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

void grabar(FILE *f,FILE *f2)
{
    char cadena[80];
    if ((f=fopen("texto.txt","r"))!=NULL&&(f2=fopen("texto2.txt","w"))!=NULL)
    {
        
        while (fgets(cadena,80,f))
        {
            fputs(cadena, f2);
        }
        fclose(f);fclose(f2);
    }
    else
    {
        printf("no se pudo abrir el archivo");
    }
    
}