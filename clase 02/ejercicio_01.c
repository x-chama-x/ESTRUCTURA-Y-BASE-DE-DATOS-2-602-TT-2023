/* 20/03/2022
ejercicio_01: Determinar la salida del programa sin ejecutar. Explicar linea a linea que sucede.
programa hecho por x_chama_x */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p,*q; // declaración de dos punteros a enteros p y q
    p=(int *) malloc(sizeof(int)); // se reserva memoria dinámicamente para p (tamaño de un entero)
    *p=5; // se asigna el valor 5 al puntero p 
    q=p;  // q apunta a la misma dirección que p
    *q=2; // se asigna el valor 2 al puntero q
    printf("p apunta a la direccion %X, que contiene %d\n,",p,*p);// se muestran en pantalla el valor y la posición de memoria apuntada por p
    printf("q apunta a la direccion %X, que contiene %d\n",q,*q); // se muestran en pantalla el valor y la posición de memoria apuntada por q
    q=(int *) malloc(sizeof(int)); // se reserva memoria dinámicamente para q (tamaño de un entero)
    *q=8; // se asigna el valor 8 al puntero q
    printf("\n ahora vemos despues de las nuevas asignaciones\n");
    printf("p apunta a la direccion %X que contiene %d\n",p,*p); // se muestran en pantalla el valor y la posición de memoria apuntada por p
    printf("q apunta a la direccion %X que contiene %d\n",q,*q); // se muestran en pantalla el valor y la posición de memoria apuntada por q
    free(p); // se libera la memoria asignada a p
    free(q); // se libera la memoria asignada a q
    return 0;
}