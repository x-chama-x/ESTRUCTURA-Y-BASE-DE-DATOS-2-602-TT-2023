/* 17/04/2023
ejercicio_02: 
    a) Dada la siguiente estructura, cargar con valores en los cuales se 
    puedan ingresar temperaturas minimas y maximas teniendo
    en cuenta que minima nunca es > que maxima, caso contrario
    repetir el ingreso.

    b) se pide que se ingresen esos datos, se muestren.
    sin repeticion y se calcule la amplitud maxima.

    c) se determina cual fue la amplitud maxima
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{
    int cod_ciudad;
    char nom_ciudad[80];
    float t_min;
    float t_max;
    float dif_ter;
}registro;


void cargarArchivo(FILE *);
int buscarCodigo(FILE *,int);
void mostrarArchivo(FILE *);
float verificarTempMin(float);
int verificarCodCiudad(FILE *,int);
void determinarAmpMax(FILE *);
void tecla();

int main ()
{
    FILE *f;
    if ((f=fopen("ciudades.dat", "rb+"))==NULL) // si existe el archivo, lo uso, sino lo creo
        f=fopen("ciudades.dat", "wb+"); 
        cargarArchivo(f);
        mostrarArchivo(f);
        determinarAmpMax(f);
    fclose(f);
    return 0;
}

void cargarArchivo(FILE *f)
{
        registro datos;
        int flag=0;
        do
        {
            system("cls");
            printf("cod_ciudad=-1 para finalizar carga");
            printf("\ningrese el codigo de ciudad: ");
            scanf("%d",&datos.cod_ciudad);
            datos.cod_ciudad=verificarCodCiudad(f,datos.cod_ciudad);
            if (datos.cod_ciudad!=-1)
            {
                printf("ingrese el nombre de la ciudad: " );
                fflush(stdin);
                gets(datos.nom_ciudad);
                printf("ingrese la temperatura maxima:  " );
                scanf("%f",&datos.t_max);
                datos.t_min=verificarTempMin(datos.t_max);
                datos.dif_ter=datos.t_max-datos.t_min;
                fseek(f, 0L, SEEK_END);
                fwrite(&datos, sizeof(datos), 1, f);
            }
        } while (datos.cod_ciudad!=-1);
}

int buscarCodigo(FILE *f,int codigoIngresado)
{
    registro datos;
    int flag=1; 
    rewind(f);
    fread(&datos,sizeof(datos),1,f);
	while (!feof(f)&&flag)
	{
        if (datos.cod_ciudad!=codigoIngresado)
        {
            fread(&datos,sizeof(datos),1,f);
        }
        else
        {
            flag=0;
        }
	}
    return flag;
} // flag==1 --> son distintos,  flag==0 --> son iguales

void mostrarArchivo(FILE *f) 
{
    system("cls");
    registro datos;
    rewind(f); // reset file position indicator
    printf("%-10s%-25s%-10s%-10s%-10s", "CODIGO", "CIUDAD", "TMIN", "TMAX", "DIFTER\n");
    printf("--------------------------------------------------------\n");
    while (fread(&datos, sizeof(datos), 1, f) == 1) // while there's something to read
    {
        printf("%-10d%-25s%-10.2f%-10.2f%-10.2f\n",datos.cod_ciudad, datos.nom_ciudad, datos.t_min, datos.t_max, datos.dif_ter);
    }
}

float verificarTempMin(float max)
{
    int flag=0;
    float min;
    do
    {
        flag=0;
        printf("ingrese la temperatura minima:  " );
        scanf("%f",&min);
        if (min>max)
        {
            flag=1;
            system("cls");
            printf("la temp_min > temp_max\n" );
            tecla();
        } 
    } while (flag==1);
    return min;
}

void tecla()
{
    printf("pulse una tecla para continuar...");
    getch();
    system("cls");
}

int verificarCodCiudad(FILE *f, int cod)
{
            while(buscarCodigo(f,cod)==0) // se ha ingresado un codigo existente)
            {
                system("cls");
                printf("se ha ingresado el mismo codigo\n");
                tecla();
                printf("cod_ciudad=-1 para finalizar carga");
                printf("\ningrese el codigo de ciudad: ");
                scanf("%d",&cod);
            }
            return cod;
}

void determinarAmpMax(FILE *f)
{
    registro datos;
    float max_amp = 0;
    rewind(f); 
    while (fread(&datos, sizeof(datos), 1, f) == 1) 
    {
        if (datos.dif_ter > max_amp) {
            max_amp = datos.dif_ter;
        }
    }
    printf("\nLa amplitud maxima es: %.2f ", max_amp);
}