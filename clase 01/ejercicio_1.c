/* 13/03/2023
ejercicio_01: Realizar un programa que dado un vector de 20 posiciones se cargue 
mediante una funcion llamada cargar con datos aleatorios entre 1 y 200.
Se necesita desgranar (abrir) ese vector en otros 2 vectores 
que van a tener los numeros primos y los numeros compuestos.
Se tienen que llamar vecPrim y vecComp en una función llamada desgranar.
Para poder ver la información generada, desarrollar una función llamada mostrarVector, 
la cual pasandole de a 1 vector a la vez. Como parametros tendra miVector, 
cantElementosVector, y un titulo.
programa hecho por x_chama_x */

#include <stdio.h>
#include <time.h>
#include <stdlib.h> // para usar la funcion rand y que no aparezcan errores

#define n 20 // cantidad de elementos de todos los vectores
void cargar(int []);
void desgranar(int [], int [], int []);
void mostrarVector(int []);

int main()
{
    int vecPrim[n] = {0};
    int vecComp[n] = {0};
    srand(time(NULL)); // funcion para generar numeros al azar (semilla aleatoria)
    int vector[n] = {0};
    cargar(vector);
    desgranar(vector,vecPrim,vecComp);
    printf("\nnumeros primos: ");
    mostrarVector(vecPrim);
    printf("\nnumeros compuestos: ");
    mostrarVector(vecComp);
    return 0;
}

void cargar(int vector [])
{
    for (int i = 0; i < n; i++)
    {
        vector[i] = rand()%(200-1+1)+1;
    }
}


void desgranar(int vector [],int vecPrim [],int vecComp [])
{
    for (int i = 0; i < n; i++)
    {
        if (vector[i]==0||vector[i]==1)
        {
            vecComp[i]=vector[i];
        }
        else if (vector[i]==4)
        {
            vecComp[i]=vector[i];
        }
        for (int x = 2; x <= vector[i] / 2 + 1; x++) 
        {
            if (vector[i] % x == 0)
            {
                vecComp[i]=vector[i];
                break;
            }
            else if (x == vector[i] / 2 + 1)
            {
                vecPrim[i]=vector[i];
            }
            else if (vector[i] == 2)
            {
                vecPrim[i]=vector[i];
            }
        }
    }
}
void mostrarVector(int vector[])
{
    for (int i = 0; i < n; i++)
    {
        if (vector[i] != 0)
        {
            printf("%d, ",vector[i]);
        }
    }
}