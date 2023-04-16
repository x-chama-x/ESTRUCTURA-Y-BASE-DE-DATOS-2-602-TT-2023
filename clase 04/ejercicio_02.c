/* 03/04/2023
ejercicio_02:
programa hecho por x_chama_x */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define lon 20

typedef struct
{
    int cod_art;
    char nom_art[lon];
    float sto_art;
    float fact_art;
} regArt;

typedef struct
{
    int cod_cli;
    char nom_cli[lon];
    float cuenta;
} regCli;

void Inicio(FILE *, FILE *);
void MostrarCli(FILE *);
void MostrarArt(FILE *);
void Linea(int);
int Error(char *);
void Tecla(void);

int main()
{
    FILE *Cli, *Art;
    int i;
    char nomArchiCli[] = "Clientes.dat";
    char nomArchiArt[] = "Articulos.dat";
    system("cls");
    system("Color 0A");
    if ((Cli = fopen(nomArchiCli, "wb+")) == NULL)
    {
        exit(Error(nomArchiCli));
    }
    if ((Art = fopen(nomArchiArt, "wb+")) == NULL)
    {
        exit(Error(nomArchiArt));
    }
    fflush(stdin);
    Inicio(Cli, Art);
    system("cls");
    MostrarCli(Cli);
    Linea(80);
    MostrarArt(Art);
    Linea(80);
    Tecla();
    system("cls");
    fclose(Cli);
    fclose(Art);
    return 0;
}

void Linea(int x)
{
    int i;
    for (i = 1; i < x; i++)
    {
        printf("*");
    }
    printf("\n");
}

void Inicio(FILE *x, FILE *y)
{
    regCli c;
    regArt a;
    char nomCli[][lon] = {"Lopez", "Rodriguez", "Garcia", "Martinez", "Perez"};
    char nomArt[][lon] = {"Coca Cola", "Agua Mineral", "Fanta", "Sprite", "Mandarina", "Pomelo"};
    float pre[] = {200.70, 300.75, 300.66, 200.80, 200.89, 300.01};
    int sto[] = {73, 129, 76, 34, 77, 98};
    for (int i = 0; i < 5; i++)
    {
        c.cod_cli = i + 1;
        strcpy(c.nom_cli, nomCli[i]);
        c.cuenta = 0;
        fseek(x, 0L, SEEK_END);
        fwrite(&c, sizeof(c), 1, x);
    }
    for (int i = 0; i < 6; i++)
    {
        a.cod_art = i + 1;
        strcpy(a.nom_art, nomArt[i]);
        a.sto_art = sto[i];
        a.fact_art = 0.0;
        fseek(y, 0L, SEEK_END);
        fwrite(&a, sizeof(a), 1, y);
    }
}

int Error(char *x)
{
    fprintf(stderr, "no se puede abrir el archivo: %s", x);
    return 1;
}

void Tecla(void)
{
    printf("\nPresione una tecla para continuar...");
    getch();
}

void MostrarCli(FILE *x)
{
    regCli c;
    rewind(x);
    printf("\n\nNomina de clientes\n\n");
    printf("\nCodigo\tNombre\t\t\t\t\t\tSaldo\n\n");
    fread(&c, sizeof(c), 1, x);
    while (!feof(x))
    {
        printf("\n%3d\t%-20s\t\t\t\t%5.2f\n", c.cod_cli, c.nom_cli, c.cuenta);
        fread(&c, sizeof(c), 1, x);
    }
}


void MostrarArt(FILE *y)
{
    regArt a;
    rewind(y);
    printf("\n\nNomina de articulos\n\n");
    printf("\nCodigo\tNombre\t\t\t\t\t\tStock\t\t\tFactura\n\n");
    fread(&a, sizeof(a), 1, y);
    while (!feof(y))
    {
        printf("\n%3d\t%-20s\t\t\t\t%4.2f,\t\t\t %2.2f\n", a.cod_art, a.nom_art, a.sto_art,a.fact_art);
        fread(&a, sizeof(a), 1, y);
    }


}