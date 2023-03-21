/* 20/03/2022
ejercicio_03: Hacer un programa que pida al usuario la cantidad de elementos que necesita 
almacenar para ella realizar una función cargar. Lugo mostrar ese vector, 
pasandole el titulo de " vector Desordenado "- Luego ordenar ese vector y 
mostrarlo con el titulo "Vector ordenado"., por último liberar ese espacio.
programa hecho por x_chama_x */

#include <stdio.h>
#include <time.h>
#include <stdlib.h> // para usar la funcion rand y que no aparezcan errores

void cargar(int ,int *);
void mostrar(int ,int *);
void ordenar(int ,int *);

int main ()
{
    srand(time(NULL)); // funcion para generar numeros al azar (semilla aleatoria)
    int n,*vector;
    printf("ingresar cantidad de elementos del vector: ");
    scanf("%d",&n);
    vector=(int *) malloc(n*sizeof(int));
    cargar(n,vector);
    printf("vector desordenado: ");
    mostrar(n,vector);
    printf("vector ordenado: ");
    ordenar(n,vector);
    mostrar(n,vector);
    free(vector);
    return 0;
}

void cargar(int n, int *vector)
{
    for (int i = 0; i < n; i++)
    {
        *vector = rand()%(10)+1;
        vector++;
    }
}

void mostrar(int n, int *vector)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ",*vector);
        vector++;
    }
}

void ordenar(int n, int *vector)
{
    int i, j, menor, temp;
    
    for (i = 0; i < n-1; i++)
    {
        menor = i;
        
        for (j = i+1; j < n; j++)
        {
            if (*(vector+j) < *(vector+menor))
                menor = j;
        }
        
        if (menor != i)
        {
            temp = *(vector+i);
            *(vector+i) = *(vector+menor);
            *(vector+menor) = temp;
        }
    }
}

