/* 20/03/2022
ejercicio_04: Realizar un programa que, dada la captura de una cadena, se pueda determinar lo siguiente:
    1) El largo de la cadena, realizando una funcion llamada cuentaCaracteres
    2) La cantidad de palabras ingresadas, realizando una función llamada cuentaPal
    3) La cantidad de letras y números que posee ese texto ingresado, realizando una función cuentaLetras
    4) Convertir la cadena ingresada en mayuscula, en esa conversión dejarla en otra cadena, realizarlo en una función Mayu
    5) Mostrar la cadena en forma invertida (recursividad)
    6) Dada la cadena que ingrese, devolver la última palabra de esa cadena en otro vector, Hacer una función llamada última.
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define n 30

void cuentaCaracteres(char [n]);
void cuentaPal(char [n]);
void cuentaLetras(char [n]);
void mayu(char [n]);
void invertirCadena(char [], int);
void ultima(char [n]);
int main()
{
    char cad [n];
    printf("ingresar un texto: ");
    gets(cad);
    cuentaCaracteres(cad);
    cuentaPal(cad);
    cuentaLetras(cad);
    mayu(cad);
    printf("\nCadena invertida: ");
    invertirCadena(cad, strlen(cad));
    ultima(cad);
    return 0;
}

void cuentaCaracteres(char cad [n])
{
    int i=0;
    while (cad[i]!='\0')
    {
        i++;
    }
    printf("largo de la cadena: %d",i);
}

void cuentaPal(char cad [n])
{
    int i=0,palabras=0;
    while (cad[i]!='\0')
    {
        if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z') || (cad[i] >= '0' && cad[i] <= '9' ))
        {
            if (i == 0 || cad[i-1] == ' ')
            {
                palabras++;
            }
        }
        i++;
    }
    printf("\ncantidad de palabras: %d",palabras);
}

void cuentaLetras(char cad [n]) {
    int letras = 0;
    int numeros = 0;
    int i = 0;
    
    while (cad[i] != '\0') {
        if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z')) {
            letras++;
        }
        else if (cad[i] >= '0' && cad[i] <= '9') {
            numeros++;
        }
        i++;
    }

    printf("\nCantidad de letras: %d", letras);
    printf("\nCantidad de numeros: %d", numeros);
}

void mayu(char cad[n])
{
    char cadMayu[n];
    for (int i = 0; i <= strlen(cad); i++)
    {
        cadMayu[i]=toupper(cad[i]);
    }
    printf("\nCadena en mayuscula: %s", cadMayu);
}

void invertirCadena(char cad[], int len){
    if(len==0){
        return;
    }
    else{
        invertirCadena(cad+1, len-1);
        printf("%c", cad[0]);
    }
}

void ultima(char cad[n])
{
    char ultPalabra[n];
    int len = strlen(cad);
    int i = len - 1;
    
    while (i >= 0 && cad[i] != ' ')
    {
        i--;
    }
    
    if (i < 0)
    {
        strcpy(ultPalabra, cad);
    }
    else
    {
        strcpy(ultPalabra, &cad[i+1]);
    }
    
    printf("\nUltima palabra: %s", ultPalabra);
}