/* 29/05/2023
Realizar un menu que contenga acolar, desacolar. listar ,vaciar y pasar a un archivo binario los elementos de la cola.
programa hecho por x_chama_x */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} nodo;

nodo* ingresar_dato(void);
void acolar(nodo* r, nodo** p, nodo** q);
nodo* verificar(nodo* p);
nodo* desacolar(nodo** p);
void dato_eliminado(nodo* r);
void vaciar(nodo** p);
void listar(nodo* p);
void pasarAArchivo(nodo* r);
void leerArchivo(nodo* r);

int main() {
    int opcion;
    nodo* p = NULL;
    nodo* fin = NULL;

    do {
        system("cls");
        printf("Menu de Cola\n");
        printf("1. Ingresar dato\n");
        printf("2. Desacolar dato\n");
        printf("3. Vaciar cola\n");
        printf("4. listar cola\n");
        printf("5. Listar Archivo\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                nodo* r = ingresar_dato();
                acolar(r, &p, &fin);
                getchar();
                break;
            }
            case 2: {
                nodo* r = verificar(p);
                if (r != NULL) {
                    r = desacolar(&p);
                    dato_eliminado(r);
                }
                break;
            }
            case 3:
                vaciar(&p);
                printf("Cola vaciada.\n");
                break;
            case 4:
                listar(p);
                break;
            case 5:
                leerArchivo(p);
                getchar();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

        printf("\nPresione Enter para continuar...");
        getchar();
    } while (opcion != 6);

    return 0;
}

nodo* ingresar_dato(void) {
    nodo* r = (nodo*)malloc(sizeof(nodo));
    system("cls");
    printf("Ingrese un Nro: ");
    scanf("%d", &(r->dato));
    r->sig = NULL;
    return r;
}

void acolar(nodo* r, nodo** p, nodo** q) {
    nodo* nuevo = r;
    if (*p == NULL)
        *p = nuevo;
    else
        (*q)->sig = nuevo;
    *q = nuevo;
}

nodo* verificar(nodo* p) {
    if (p == NULL) {
        system("cls");
        printf("COLA VACIA!!\n\n\n\n");
        getchar();
        return NULL;
    }
    return p;
}

nodo* desacolar(nodo** p) {
    nodo* r = *p;
    *p = (*p)->sig;
    r->sig = NULL;
    return r;
}

void dato_eliminado(nodo* r) {
    system("cls");
    printf("Valor Eliminado: %d\n", r->dato);
    pasarAArchivo(r);
    free(r);
    getchar();
}

void pasarAArchivo(nodo* r)
{   
    FILE *f;     
    if ((f=fopen("desacolados.dat", "rb+"))==NULL) // si existe el archivo, lo uso, sino lo creo
    f=fopen("desacolados.dat", "wb+");
    fseek(f,0L,SEEK_END);
    fwrite(&r->dato, sizeof(int), 1, f);
    fclose(f);
}

//pasarAArchivo() el dato desacolado debe pasar a un archivo binario


void leerArchivo(nodo* r){
    FILE *f;
    int dato; 
    system("cls");
    printf("datos desacolados: ");
    f=fopen("desacolados.dat", "rb"); 
    if(f == NULL){ 
        printf("Error: No se pudo abrir el archivo");
    }
    while(fread(&dato, sizeof(int), 1, f)){
        printf("%d ", dato);
    }
    printf("\n"); 
    fclose(f); 
}

void vaciar(nodo** p) {
    nodo* aux;
    while (*p != NULL) {
        aux = *p;
        *p = (*p)->sig;
        free(aux);
    }
}

void listar(nodo* p) {
    system("cls");
    printf("Elementos en la cola:\n");
    while (p != NULL) {
        printf("%d ", p->dato); // se imprime en pantalla el dato del nodo actual
        p = p->sig; // se pasa al siguiente nodo en la pila
    }
    getchar();
}


