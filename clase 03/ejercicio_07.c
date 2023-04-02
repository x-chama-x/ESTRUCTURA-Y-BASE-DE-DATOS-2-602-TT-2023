/* 27/03/2023
ejercicio_07: Analizar si los siguientes textos 
son palindromos en un programa en c
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define n 100

int sonPalindromos(char *cadena);

int main()
{
    FILE *f;
    int i=1;
    if ((f=fopen("palindromos.txt","rt"))!=NULL)
    {
        char cadena[n];
        while ((fgets(cadena,n,f))!=NULL)
        {
            if ((sonPalindromos(cadena))==1)
            {
                printf("el texto %d es palindromo\n",i);
            }
            else
            {
                printf("el texto %d no es palindromo\n",i);
            }
            i++;
        }
        fclose(f);
    }
    else
    {
        printf("no se pudo abrir el archivo");
    }
    return 0;
}

int sonPalindromos(char *cadena) {
    int i, j;
    int longitud = strlen(cadena) - 1; // no contar el carácter nulo '\0' al final
    for (i = 0, j = longitud; i < j; i++, j--) {
        // ignorar espacios y puntuación
        while (i < longitud && !isalnum(cadena[i])) {
            i++;
        }
        while (j > 0 && !isalnum(cadena[j])) {
            j--;
        }
        // comparar caracteres
        if (cadena[i] != cadena[j]) {
            return 0; // no es palíndromo
        }
    }
    return 1; // es palíndromo
}


