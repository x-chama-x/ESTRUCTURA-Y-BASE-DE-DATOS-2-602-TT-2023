#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#define p printf
#define s scanf

typedef struct
{
int cod_art;
char nom_art[20];
float pre_art;
int sto_art;
float fact_art;
} regarti;
typedef struct
{
int cod_cli;
char nom_cli[20];
float cuenta;
}regcli ;


void inicio(FILE*,FILE*);
void ingresar(FILE*,FILE*);
void mostrar(FILE*,FILE*);
int error(char*);
void tecla(void);
void linea(int);

// funciones mias
int verificarCodigoCliente(int);
int verificarCodigoArt(int);




main()
{
	FILE *cli,*art;
	char nomarchcli[]="clientes.dat";
	char nomarchart[]="articulos.dat";
	system("cls"); srand(time(NULL)); system("color 9f");
	if((cli=fopen(nomarchcli,"wb+"))==NULL)
		exit(error(nomarchcli));
	p("\nEl archivo %s ha sido cargado!!",nomarchcli);

	if((art=fopen(nomarchart,"wb+"))==NULL)
		exit(error(nomarchart));
	p("\nEl archivo %s ha sido cargado!!",nomarchart);

	tecla();
	fflush(stdin);
	inicio(cli,art);
	//system("cls");
	mostrar(cli,art);
	ingresar(cli,art);
	mostrar(cli,art);
	linea(80);
	tecla();            //lo muestro
	system("cls");
	fclose(cli);fclose(art);
	return(0);

}
void linea(int x)
{
 int i;
	//p("");
	for(i=1;i<x;i++)
	 p("*");
// p("\n");
}

void inicio(FILE *x,FILE*y)
{
 regcli c;
 regarti a;
 char nomcli[][20]={"LOPEZ","RODRIGUEZ","GARCIA","MARTINEZ","LOLI"};
 char nomart[][20]={"COCA COLA","AGUA TONICA","N.FANTA","SPRITE","POMELO","MANDARINA"};
 float pre[]={2.70,3.75,3.66,2.80,2.89,3.01};
 int sto[]={73,120,76,34,77,98};
 int i;
 for(i=0;i<5;i++)
 {
	 c.cod_cli=i+1;
	 strcpy(c.nom_cli,nomcli[i]);
	 c.cuenta=0.;
	 fseek(x,0L,SEEK_END);
	 fwrite(&c,sizeof(c),1,x);
	 }

for(i=0;i<6;i++)
 {
	 a.cod_art=i+1;
	 strcpy(a.nom_art,nomart[i]);
	 a.pre_art=pre[i];
	 a.sto_art=sto[i];
	 a.fact_art=0.;
	 fseek(y,0L,SEEK_END);
	 fwrite(&a,sizeof(a),1,y);
	 }

}

void mostrar(FILE *x,FILE*y)
{
	regcli c;
	regarti a;
	rewind(x);
	system("cls");
	p("\n\n\t\t\tN%cMINA DE CLIENTES\n\n",224);
	linea(80);
	p("\nC%cDIGO\tNOMBRE\t\t\t\t\t\tSALDO\n",224);
	fread(&c,sizeof(c),1,x);
	while(!feof(x))
	{
		p("\n%3d\t%-20s\t\t\t\t%6.2f\n",c.cod_cli,c.nom_cli,c.cuenta);
		fread(&c,sizeof(c),1,x);
	}
	p("\n");
	rewind(y);
	linea(80);
	p("\n\n\t\t\t N%cMINA DE ART%cCULOS\n\n",224,214);
	linea(80);
	p("\nC%cDIGO\tART%cCULO\t\t\tSTOCK\t\tFACTURACI%cn\n",224,214,224);
	fread(&a,sizeof(a),1,y);
	while(!feof(y))
	{
		p("\n%3d\t%-20s\t\t%3d\t\t%8.2f\n",a.cod_art,a.nom_art,a.sto_art,a.fact_art);
		fread(&a,sizeof(a),1,y);
	}
}

void ingresar(FILE *cl,FILE*ar)
{
    regarti a;
    regcli c;
    int nFactura,codCliente,codArt,cantArt;
    float cantLitros, total;

    
    do
    {
        p("\nIngresar numero de factura (0 para finalizar): "); // 1 buscar factura
        s("%d",&nFactura);
        if(nFactura!=0)
        {
            do
            {
                system("cls");
                printf("Ingresar codigo del cliente (1-5): "); // 2 buscar cliente
                s("%d", &codCliente);
            } while (verificarCodigoCliente(codCliente)==1);

            do
            {
                system("cls");
                p("Ingrese codigo del articulo (1-6) (0 para volver a ingresar factura): ");
                s("%d",&codArt);
            } while (verificarCodigoArt(codArt)==1);
            

            if (verificarCodigoArt(codArt)!=-1)
            {
                int flag;
                do
                {
                    system("cls");
                    p("Ingrese la cantidad del producto: "); // 3 buscar cant para ver stock
                    s("%d",&cantArt);

                    // verificar Stock
                    rewind(ar);
                    while(!feof(ar)) 
                    {
                        fread(&a,sizeof(a),1,ar);
                        if(a.cod_art==codArt)
                        {
                            if(a.sto_art>cantArt)
                            {
                                flag= 0; // hay stock
                            }
                            else
                            {
                                p("No hay suficiente stock de %s.\n", a.nom_art);
                                fclose(ar);
                                flag = 1; // no hay stock
                            } 
                        }
                    }

                } while (flag==1);

                // 4 buscar cant de litros
            p("Ingrese la cantidad de litros: ");
            s("%f", &cantLitros);
                
            }

            // calcular el total
            total = a.pre_art * cantArt;

            // Actualizar la facturacion y el stock del articulo en sus respectivos archivos
             a.fact_art += total;
             a.sto_art -= cantArt;
             fseek(ar, -(long)sizeof(a), SEEK_CUR);
             fwrite(&a, sizeof(a), 1, ar);
            // Actualizar la cuenta del cliente en el archivo de clientes
            c.cuenta += total;
            fseek(cl, -(long)sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(c), 1, cl);

        }
    } while (nFactura!=0);
    p("\nfacturacion completada!!\n");
    tecla();
}


int verificarCodigoCliente(int codCliente){
    if (codCliente < 1 || codCliente > 5) {
        system("cls");
        p("Código de cliente inválido.\n");
        return 1; // retorna cliente invalido
    }
    else
    {
        return 0; // retorna cliente valido
    }
}

int verificarCodigoArt(int codArt){
    if (codArt < 1 || codArt > 6) 
    {
        if (codArt==0)
        {
            return -1; // carga de datos de la factura finalizo
        }
        else
        {
            system("cls");
            p("Código de articulo inválido.\n");
            return 1; // retorna articulo invalido
        }
    }
    else
    {
        return 0; // retorna articulo valido
    }
}



int error(char *x)
{
	fprintf(stderr,"no se puede abrir el archivo %s",x);
	return(1);
}
void tecla(void)
{
	p("\nPRESIONE CUALQUIER TECLA PARA CONTINUAR!!!");
	getch();
}




