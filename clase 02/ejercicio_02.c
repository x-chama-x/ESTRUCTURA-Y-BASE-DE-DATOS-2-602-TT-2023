/* 20/03/2022
ejercicio_02: Dado el siguiente vector, utilizar un puntero y recorrerlo con él.
programa hecho por x_chama_x */

#include <stdio.h>
int main()
{
    int lista[] ={24,30,15,45,34};
    int *p=lista;
    printf("lista: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ",*p);
        p++;
    }
    return 0;
}