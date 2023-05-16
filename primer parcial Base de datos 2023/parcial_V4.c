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
	system("cls");
	mostrar(cli,art);
	ingresar(cli,art);
    system("cls");
	mostrar(cli,art);
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

void mostrar(FILE *x, FILE *y) {
    // modifique la funcion mostrar porque me mostraba 2 veces la nomina de clientes. Ahora me lo muestra bien.
    regcli c;
    regarti a;
    rewind(x);
    printf("\n\t\t\tNOMINA DE CLIENTES");
    printf("\nCODIGO\tNOMBRE\t\t\t\t\t\t  SALDO");
    fread(&c, sizeof(c), 1, x);
    while(!feof(x)) {
        printf("\n%3d\t%-20s\t\t\t\t%6.2f", c.cod_cli, c.nom_cli, c.cuenta);
        fread(&c, sizeof(c), 1, x);
    }
    printf("\n");
    
    rewind(y);
    printf("\n\t\t\tNOMINA DE ARTICULOS");
    printf("\nCODIGO\tARTICULO\t\t\tSTOCK\t\tFACTURACION");
    fread(&a, sizeof(a), 1, y);
    while(!feof(y)) {
        printf("\n%3d\t%-20s\t\t%3d\t\t%8.2f", a.cod_art, a.nom_art, a.sto_art, a.fact_art);
        fread(&a, sizeof(a), 1, y);
    }
}

void ingresar(FILE* cl, FILE* ar) {
    regcli c;
    regarti a;
    int nFactura, codCliente, codArt, cantArt, i;
    float cantLitros, total;
    do
    {
        printf("\nIngresar numero de factura (0 para finalizar): ");
        scanf("%d", &nFactura);
        if(nFactura!=0)
        {
            do{
                printf("Ingresar codigo del cliente (1-5): ");
                scanf("%d", &codCliente);
            } while ((codCliente < 1 || codCliente > 5));
            
            do
            {
                do
                {
                    printf("Ingresar codigo del articulo (1-6) (0 para volver a ingresar factura): ");
                    scanf("%d", &codArt);
                } while (codArt < 0 || codArt > 6);

                if (codArt != 0) {
                    printf("Ingresar cantidad del articulo: ");
                    scanf("%d", &cantArt);

                    rewind(ar);
                    i = 0;
                    while (!feof(ar)) {
                        fread(&a, sizeof(a), 1, ar);
                        if (a.cod_art == codArt) {
                            if (a.sto_art < cantArt) {
                                printf("No hay suficiente stock.\n");
                                return;
                            } else {
                                a.sto_art -= cantArt;
                                a.fact_art += cantArt * a.pre_art;
                                total = cantArt * a.pre_art;
                            }
                            fseek(ar, sizeof(a) * i, SEEK_SET);
                            fwrite(&a, sizeof(a), 1, ar);
                            break;
                        }
                        i++;
                    }

                    rewind(cl);
                    while (fread(&c, sizeof(c), 1, cl)) {
                        if (c.cod_cli == codCliente) {
                            c.cuenta += total;
                            fseek(cl, -sizeof(c), SEEK_CUR);
                            fwrite(&c, sizeof(c), 1, cl);
                            break;
                        }
                    }
                }
                system("cls"); 
            } while (codArt!=0);
        }
    } while (nFactura!=0); 
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




