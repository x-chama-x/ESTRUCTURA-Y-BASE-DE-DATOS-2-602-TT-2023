/* 19/03/2022
ejercicio_02: Mostrar el vector v[10] normal, como si fuera un puntero, 
la direccion del vector,la dirección del puntero.
Mostrar el codigo en hexa con %X
programa hecho por x_chama_x */

#include <stdio.h>
int main()
{
    int v[10] = {10,20,30,40,50,60,70,80,90,100};

    // impresion del vector "normal"

    printf("vector v: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ",v[i]);
    }

    // impresion del vector "como si fuera un puntero"
    
    int *ptr = v; // ptr apunta a la dirección de memoria del primer elemento de v
    printf("\nvector v (usnado un puntero): ");
    for(int i = 0; i < 10; i++) 
    {
        printf("%d ", *ptr); // se imprime el valor al que apunta ptr
        ptr++; // se incrementa el puntero para apuntar al siguiente elemento
    }

    // impresion de la dirección de memoria de cada elemento del vector.

    printf("\ndireccion de memoria del vector v: ");
    for(int i = 0; i < 10; i++) 
    {
        printf("%X, ", &v[i]);  
    }

    // impresion de la dirección del puntero

    printf("\ndireccion de memoria del puntero ptr: %X", &ptr);
    return 0;
}