/* 19/03/2023
ejercicio_01: Dada la siguiente estructura, Ordenar por nombre de rubro y mostrar 
programa hecho por x_chama_x */
#include <stdio.h>
#include <string.h>
#define n 5
typedef struct
{ 
	int codRubro;
	char nomRubro[25];
	float precio; 
} registro;
void mostrar(registro[]);
void ordenar(registro[]);
int main()
{
	registro rubro[n]= {{1,"Automotor",15.25},
	                    {2,"Oficinas",12.46},
	                    {3,"Profesionales",14.80},
	                    {4,"Escobas",48.34},
	                    {5,"Servicios",10.54},};
	
    
    ordenar(rubro);
    mostrar(rubro);
    return 0;
}

void ordenar(registro rubro[])
{
    int i, j, min_idx;
    registro temp;
    
    // se itera sobre todos los elementos del arreglo
    for (i = 0; i < n-1; i++)
    {
        // se encuentra el elemento mínimo en el resto del arreglo
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (strcmp(rubro[j].nomRubro, rubro[min_idx].nomRubro) < 0)
                min_idx = j;

        // se intercambia el elemento mínimo con el primer elemento
        temp = rubro[i];
        rubro[i] = rubro[min_idx];
        rubro[min_idx] = temp;
    }
}

void mostrar(registro rubro[])
{
    int i;
    printf("%-10s %-25s %s\n", "Codigo", "Nombre de rubro", "Precio");
    for (i = 0; i < n; i++)
    {
        printf("%-10d %-25s %.2f\n", rubro[i].codRubro, rubro[i].nomRubro, rubro[i].precio);
    }
}
