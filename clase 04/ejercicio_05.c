/* 15/04/2023
ejercicio_05: Tomar notas.txt y lo pasamos a 2 archivos binarios aprobado.dat y desaprobado.dat
programa hecho por x_chama_x */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int legajo;
    float nota;
    char nombreApellido[30];
}datos;

int saberCantLineas(); // cuento la cantidad de lineas del archivo txt
void procesarArchivoTexto(int,datos []); // abre el archivo de txt y pasa los datos al struct
void procesarNotas(int, datos []); // pasa los datos del struct a los 2 archivos de texto binarios, depeniendo de la nota
void mostrarArchivosBin();

int main()
{
    int n = saberCantLineas();
    datos alumno[n];
    procesarArchivoTexto(n,alumno);
    procesarNotas(n,alumno);
    mostrarArchivosBin();
    return 0;
}

int saberCantLineas()
{
    FILE *f;
    char *res,cadena[100];
    if ((f=fopen("notas.txt","r"))!=NULL)
    {
        int i=0;
        while ((res=fgets(cadena,100,f))!=NULL)
        {  
            i++;
        }
        fclose(f);
        return i;
    }
    else
    {
        printf("error al abrir el archivo");
    }  

}

void procesarArchivoTexto(int n, datos alumno[n])
{
    FILE *f;
    char *res;
    char cadena[100];
    if ((f=fopen("notas.txt","r"))!=NULL)
    {
        int i=0;
        while ((res=fgets(cadena,100,f))!=NULL)
        {
            // se extrae datos del archivo txt usando strtok()
            char *pri,*seg,*terc;
            pri=strtok(cadena,",");
            alumno[i].legajo=atoi(pri);
            seg=strtok(NULL,",");
            strcpy(alumno[i].nombreApellido, seg);
            terc=strtok(NULL,",");
            alumno[i].nota=atof(terc);
            i++;
        }
        fclose(f);
    }
    else
    {
        printf("error al abrir el archivo");
    }
}

void procesarNotas(int n,datos alumno [n])
{
    FILE *f,*f2;
    if (((f=fopen("aprobado.dat","wb"))!=NULL)&&((f2=fopen("desaprobado.dat","wb"))!=NULL))
    {
        for (int i = 0; i < n; i++)
        {
            if (alumno[i].nota>=6)
            {
                fwrite(&alumno[i],sizeof(datos),1,f);
            }else
            {
                fwrite(&alumno[i],sizeof(datos),1,f2);
            }
        }
        fclose(f);fclose(f2);
    }
    else
    {
        printf("error al abrir el archivo");
    } 
}

void mostrarArchivosBin()
{
    datos aux;
    FILE *f,*f2;
    if (((f=fopen("aprobado.dat","rb"))!=NULL)&&((f2=fopen("desaprobado.dat","rb"))!=NULL))
    {
        printf("------ Alumnos Aprobados ------\n");
        while (fread(&aux,sizeof(datos),1,f) == 1)
        {
            printf("Legajo: %d - Nota: %.2f - Nombre y Apellido: %s\n",aux.legajo,aux.nota,aux.nombreApellido);
        }
        printf("\n------ Alumnos Desaprobados ------\n");
        while (fread(&aux,sizeof(datos),1,f2) == 1)
        {
            printf("Legajo: %d - Nota: %.2f - Nombre y Apellido: %s\n",aux.legajo,aux.nota,aux.nombreApellido);
        }
        fclose(f);fclose(f2);
    }
    else
    {
        printf("Error al abrir los archivos.\n");
    } 
}

