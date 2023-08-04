#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

typedef struct elemento
{
    int dato;
    int cont;
    struct elemento *sig;
} nodo;

// Declaración de funciones
nodo *buscar(nodo *x, int y);
void borranodo(nodo **x, int y);
void insertar(nodo **x, int y);
nodo *nuevonodo(int x);
void listar(nodo *x);
void eliminar(nodo **x);

int main()
{
    nodo *cabeza = NULL, *aux;
    int opcion, valor;

    do
    {
        system("cls"); // Limpiamos la pantalla
        printf("\n--- MENU DE DATOS ---\n");
        printf("1. Insertar elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Borrar elemento\n");
        printf("4. Listar elementos\n");
        printf("5. Eliminar toda la lista\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &valor);
            insertar(&cabeza, valor);
            break;

        case 2:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &valor);
            aux = buscar(cabeza, valor);
            if (aux)
                printf("Valor encontrado en la lista.\n");
            else
                printf("Valor no encontrado en la lista.\n");
                printf("Presione una tecla para continuar.\n");
                getch(); // Esperamos una tecla antes de continuar
            break;

        case 3:
            printf("Ingrese el valor a borrar: ");
            scanf("%d", &valor);
            borranodo(&cabeza, valor);
            printf("Presione una tecla para continuar.\n");
            getch(); // Esperamos una tecla antes de continuar
            break;

        case 4:
            system("cls"); // Limpiamos la pantalla antes de listar
            printf("\n--- LISTA DE ELEMENTOS ---\n");
            listar(cabeza);
            printf("Presione una tecla para continuar.\n");
            getch(); // Esperamos una tecla antes de continuar
            break;

        case 5:
            eliminar(&cabeza);
            printf("Lista eliminada.\n");
            printf("Presione una tecla para continuar.\n");
            getch(); // Esperamos una tecla antes de continuar
            break;

        case 0:
            printf("Saliendo del programa.\n");
            break;

        default:
            printf("Opción inválida, intente de nuevo.\n");
            printf("Presione una tecla para continuar.\n");
            getch(); // Esperamos una tecla antes de continuar
            break;
        }

    } while (opcion != 0);

    return 0;
}

nodo *buscar(nodo *x, int y)
{
    if (!x)
        return NULL;
    else if (y == x->dato)
        return x;
    else
        return buscar(x->sig, y);
}

void borranodo(nodo **x, int y)
{
    nodo *aux;
    if (*x)
    {
        aux = *x;
        if ((*x)->dato == y)
        {
            printf("\nNodo a eliminar: %3d\n", (*x)->dato);
            *x = aux->sig;
            free(aux);
        }
        else
            borranodo(&(*x)->sig, y);
    }
}

void insertar(nodo **x, int y)
{
    nodo *nuevo;
    nuevo = nuevonodo(y);
    if (*x == NULL)
        *x = nuevo;
    else if ((*x)->dato > y)
    {
        nuevo->sig = *x;
        *x = nuevo;
    }
    else if (y == (*x)->dato)
        (*x)->cont++;
    else
        insertar(&(*x)->sig, y);
}

nodo *nuevonodo(int x)
{
    nodo *a;
    a = (nodo *)malloc(sizeof(nodo));
    a->dato = x;
    a->cont = 1;
    a->sig = NULL;
    return a;
}

void listar(nodo *x)
{
    if (x)
    {
        printf("%4d (%d)\n", x->dato, x->cont);
        listar(x->sig);
    }
}

void eliminar(nodo **x)
{
    nodo *aux;
    if (*x)
    {
        aux = *x;
        *x = aux->sig;
        free(aux);
        eliminar(x);
    }
}
