#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} nodo;

nodo* ingresarDato(void);
void apilar(nodo** p, nodo* q);
void listar(nodo* p);
int desapilar(nodo** p);

int main() {
    nodo* pila = NULL; // Inicializamos la pila como vacía
    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Apilar\n");
        printf("2. Listar\n");
        printf("3. Desapilar\n");
        printf("4. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Apilar un elemento
                {
                    nodo* nuevoNodo = ingresarDato(); // se pide al usuario ingresar un número y creamos un nuevo nodo
                    apilar(&pila, nuevoNodo); // se apila el nuevo nodo en la pila
                    printf("Elemento apilado con exito.\n");
                }
                break;
            case 2:
                // Listar elementos en la pila
                printf("Elementos en la pila:\n");
                listar(pila); // se muestra en pantalla los elementos de la pila
                break;
            case 3:
                // Desapilar un elemento
                {
                    int datoDesapilado = desapilar(&pila); // se desapila un elemento de la pila
                    if (datoDesapilado != -1) {
                        printf("Elemento desapilado: %d\n", datoDesapilado);
                    } else {
                        printf("La pila esta vacia.\n");
                    }
                }
                break;
            case 4:
                // Salir del programa
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4); // El programa continuará ejecutándose hasta que se seleccione la opción de salir (4)

    return 0;
}

nodo* ingresarDato(void) {
    int nro;
    nodo* q = (nodo*)malloc(sizeof(nodo)); // se reserva memoria para un nuevo nodo
    system("cls"); 

    printf("\n\nIngrese un numero: ");
    scanf("%d", &nro); // se pide al usuario ingresar un número

    q->dato = nro; // se almacena el número ingresado en el campo 'dato' del nuevo nodo
    q->sig = NULL; // El nuevo nodo se convierte en la cima de la pila, por lo que su campo 'sig' se establece como NULL

    return q; // se retorna el puntero al nuevo nodo
}

void apilar(nodo** p, nodo* q) {
    q->sig = *p; // El campo 'sig' del nuevo nodo apunta al nodo que estaba previamente en la cima de la pila
    *p = q; // El puntero de la pila apunta al nuevo nodo, convirtiéndolo en la nueva cima de la pila
}

void listar(nodo* p) {
    while (p != NULL) {
        printf("%d ", p->dato); // se imprime en pantalla el dato del nodo actual
        p = p->sig; // se pasa al siguiente nodo en la pila
    }
    printf("\n");
}

int desapilar(nodo** p) {
    if (*p == NULL) {
        return -1; // La pila está vacía
    }

    nodo* aux = *p; // se almacena el nodo de la cima de la pila en un nodo auxiliar
    int dato = aux->dato; // se almacena el dato del nodo a desapilar
    *p = (*p)->sig; // se actualiza el puntero de la pila para que apunte al siguiente nodo
    free(aux); // se libera la memoria del nodo desapilado

    return dato; // se retorna el dato del nodo desapilado
}

