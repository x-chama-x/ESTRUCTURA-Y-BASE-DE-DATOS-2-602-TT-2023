/* 27/03/2023
ejercicio_06: Idem ejercicio 5, pero tiene que dereminar 
la palabra más larga por renglón y poder mostrarlo
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#define n 80
void sonPolindromos(); //cargar texto y mostrarlo por pantalla
void palMasLarga();
int main()
{
    sonPolindromos();
    printf("\n");
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
        while (fgets(cadena,n,f))
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

void palMasLarga() {
    FILE *f;
    char cadena[n];
    int linea = 1;

    if ((f = fopen("texto.txt", "r")) != NULL) {
        while (fgets(cadena, n, f)) {
            char *palabra = strtok(cadena, " ");
            int longitud_maxima = 0, numero_palabra = 0;
            char palabra_mas_larga[n];
            while (palabra != NULL) {
                numero_palabra += 1;
                int longitud_actual = strlen(palabra);
                if (longitud_actual > longitud_maxima) {
                    longitud_maxima = longitud_actual;
                    strcpy(palabra_mas_larga, palabra);
                }
                palabra = strtok(NULL, " ");
            }
            printf("En la linea %d, la palabra mas larga es: %s\n", linea, palabra_mas_larga);
            linea += 1;
        }
        fclose(f);
    } 
    else {
        printf("no se pudo abrir el archivo\n");
    }
}