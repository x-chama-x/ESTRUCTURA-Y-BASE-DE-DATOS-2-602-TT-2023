/* 16/04/2023
ejercicio_01: 
    1. Tener en cuenta que agregar, no debe aceptar un codigo ya existente, el nombre del
    archivo es productos.dat
    2. la señal sera 1 si el registro esta activo
programa hecho por x_chama_x */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void AgregarProducto(FILE *);
void EliminarProducto(FILE *);
void ModificarProducto(FILE *);
void EliminarLogicamente(FILE *);
int MenuPrincipal(void);

int buscarCodigo(FILE *,int); // reutilizo codigo de la clase 4 ej 6
void listarProductos(FILE *); 

typedef struct 
{
    int codigo;
    char descripcion[80];
    float precio;
    int signal;
} producto;



int main()
{
    int op;
    FILE *f;
    do 
    {
        op=MenuPrincipal();
        if ((f=fopen("productos.dat", "rb+"))==NULL) // si existe el archivo, lo uso, sino lo creo
            f=fopen("productos.dat", "wb+");  
        switch (op)
        {
            case 1:
                listarProductos(f);
                fclose(f);
                op=0;
                break;
            case 2:
                AgregarProducto(f);
                fclose(f);
                op=0;
                break;
            case 3:
                EliminarProducto(f);
                fclose(f);
                op=0;
                break;
            case 4:
                ModificarProducto(f);
                fclose(f);
                op=0;
                break;
            case 5:
                EliminarLogicamente(f);
                fclose(f);
                op=0;
                break;
            case 6:
                system("cls");
                printf("saliendo del programa....");
                fclose(f);
                break;
        }
    } while (op<1||op>6); // obtener opcion
    return 0;
}


int MenuPrincipal(void)
{
    int op;
    do
    {
        system("cls");
        printf("MENU PRINCIPAL DE PRODUCTOS\n\n");
        printf("<1> Mostrar lista de productos\n");
        printf("<2> Agregar Producto\n");
        printf("<3> Eliminar fisicamente un producto\n");
        printf("<4> Modificar producto\n");
        printf("<5> Eliminar Logicamente\n");
        printf("<6> Salir\n");
        printf("ingrese opcion: ");
        scanf("%d",&op);
    } while (op<1||op>6);
    return op;
}

void AgregarProducto(FILE *f)
{
    producto p; // se crea una variable de struct ya que quiero agregar un producto solo
    int flag=0; 
    do
    {
        system("cls");
        printf("Ingrese el codigo del producto: ");
        scanf("%d",&p.codigo);
        if (buscarCodigo(f,p.codigo)==0) // se ha ingresado un codigo existente
        {
            system("cls");
            printf("se ha ingresado el mismo codigo\n");
            printf("\ningrese 1 para volver al menu principal");
            printf("\ningrese 2 para volver a ingresar el codigo");
            printf("\ningrese opcion: ");
            scanf("%d",&flag);
        }
    } while (flag==2);
    
    if (flag==1)
    {
        system("cls");
        printf("pulse una tecla para salir...");
        getch();
    }
    
    if(flag==0)
    {
        printf("Ingrese una breve descripcion del producto: ");
        fflush(stdin);
        gets(p.descripcion);
        printf("ingrese su precio: ");
        scanf("%f",&p.precio);
        p.signal=1; // se considera producto "activo"
        fseek(f,0L,SEEK_END);
        fwrite(&p, sizeof(producto), 1, f); 
    }
}

int buscarCodigo(FILE *f,int codigoIngresado) // reutilizo codigo de la clase 4 ej 6
{
    producto datos;
    int flag=1; // flag activado por defecto
    rewind(f);
    fread(&datos,sizeof(datos),1,f);
	while (!feof(f)&&flag)
	{
        if (datos.codigo!=codigoIngresado)
        {
            fread(&datos,sizeof(datos),1,f);
        }
        else
        {
            flag=0;
        }
	}
    return flag;
    // flag==1 --> son distintos,  flag==0 --> son iguales
}


void listarProductos(FILE *f)
{
	producto p;
    int op;
	rewind(f);
	fread(&p,sizeof(p),1,f);
    system("cls");
    printf("<1> Mostrar productos activos\n");
    printf("<2> Mostrar productos discontinuados\n");
    printf("<3> salir\n");
    printf("ingrese opcion: ");
    scanf("%d",&op);
    system("cls");
    switch (op)
    {
    case 1:
        rewind(f);
        fread(&p,sizeof(p),1,f);
        printf("productos activos: \n");
        while (!feof(f))
        {
            if (p.signal==1)
            {
                printf("codigo de producto: %d",p.codigo);
                printf(", descripcion: %s",p.descripcion);
                printf(", precio: $%.2f \n",p.precio);
                fread(&p,sizeof(p),1,f);
            }
            else
            {
                fread(&p,sizeof(p),1,f);
            }
        }
        printf("\n\npulse una tecla para salir...");
        getch();
        break;
    case 2:
        rewind(f);
        fread(&p,sizeof(p),1,f);
        printf("productos discontinuados: \n");
        while (!feof(f))
        {
            if (p.signal==0)
            {
                printf("codigo de producto: %d",p.codigo);
                printf(", descripcion: %s",p.descripcion);
                printf(", precio: $%.2f ",p.precio);
                fread(&p,sizeof(p),1,f);
            }
            else
            {
                fread(&p,sizeof(p),1,f);
            }
        }
        printf("\n\npulse una tecla para salir...");
        getch();
        break;
    case 3:
        printf("\npulse una tecla para salir...");
        getch();
        break;
    }
}

// creo un archivo temp para guardar todos los productos menos el que voy a eliminar
void EliminarProducto(FILE *f)
{
    int codIngr; // codigo a eliminar
    producto p;
    system("cls");
    printf("Ingrese el codigo a eliminar: ");
    scanf("%d",&codIngr);

    if (buscarCodigo(f,codIngr)==0) // se encontro el codigo a eliminar
    {
        rewind(f); 
        FILE *ftmp = fopen("temp.dat", "wb"); // creo archivo temporal
        while(fread(&p, sizeof(producto), 1, f) != 0) // mientras pueda leer productos
        {
            if(p.codigo != codIngr) // si el codigo no coincide con el a eliminar
            {
                fwrite(&p, sizeof(producto), 1, ftmp); // copio el registro completo al archivo temporal
            }
        }
        fclose(f); fclose(ftmp);
        remove("productos.dat");
        rename("temp.dat", "productos.dat");
        printf("\nEl producto con codigo %d se ha eliminado exitosamente.\n", codIngr); 
    }
    else
    {
        printf("\nEl producto con codigo %d no existe.\n", codIngr);
    }
    printf("\npulse una tecla para salir...");
    getch();
}


void EliminarLogicamente(FILE *f)
{
    int codIngr;
    producto p;
    int flag=0; // para evitar desbordamiento de lectura
    system("cls");
    printf("Ingrese el codigo a eliminar logicamente: ");
    scanf("%d",&codIngr);
    if (buscarCodigo(f,codIngr)==0) // se encontro el codigo a eliminar
    {
        rewind(f);
        while((!feof(f))&&flag==0)
        {
            fread(&p, sizeof(producto), 1, f);
            if (codIngr==p.codigo)
            {
                p.signal=0;
                fseek(f, -sizeof(producto), SEEK_CUR);
                fwrite(&p, sizeof(producto), 1, f);
                flag=1;
            }
        }
        printf("\nEl producto con codigo %d se ha eliminado (logicamente).\n", codIngr); 
    }
    else
    {
        printf("\nEl producto con codigo %d no existe.\n", codIngr);
    }
    printf("\npulse una tecla para salir...");
    getch();
}

void ModificarProducto(FILE *f)
{
    int codIngr;
    producto p;
    int flag=0; // para evitar desbordamiento de lectura
    system("cls");
    printf("Ingrese el codigo a modificar: ");
    scanf("%d",&codIngr);
    if (buscarCodigo(f,codIngr)==0) // se encontro el codigo a modificar
    {
        rewind(f);
        while((!feof(f))&&flag==0)
        {
            fread(&p, sizeof(producto), 1, f);
            if (codIngr==p.codigo)
            {
                printf("Ingrese una breve descripcion del producto: ");
                fflush(stdin);
                gets(p.descripcion);
                printf("ingrese su precio: ");
                scanf("%f",&p.precio);
                p.signal=1; // se considera producto "activo"
                fseek(f, -sizeof(producto), SEEK_CUR);
                fwrite(&p, sizeof(producto), 1, f); 
                flag=1;
            }
        }
        printf("\nEl producto con codigo %d se ha modificado.\n", codIngr); 
    }
    else
    {
        printf("\nEl producto con codigo %d no existe.\n", codIngr);
    }
    printf("\npulse una tecla para salir...");
    getch();
}