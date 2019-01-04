#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct 
{
       int no_producto;
       char nom_producto [30];
       float precio_menudeo, precio_mayoreo;
       int personal;
}serv;
FILE *ap;
void Agregar (int n,  serv y[]);
void guardarproductos (int n, serv y[]);
int mostrarservicio (int n, serv y[]);
int main()
{
    int i=0,n,opc;
    serv y[100];
    ap=fopen("servicios.txt","r");
    do
    {
        printf("Ingresa numero de servicios:  \n");
        scanf("%d",&n);
    }while (n<0 || n>100);
	if(ap==NULL) 
	{
		printf("No se encontro el archivo");
	}
	else
	{
		printf ("Hay estos servicios: \n\n");
		for(int i=0;i<4;i++)
		{
    		fscanf(ap,"%d %s %f %f %d\n", &y[i].no_producto,&y[i].nom_producto,&y[i].precio_menudeo,&y[i].precio_mayoreo,&y[i].personal);
			printf("%d %s %f %f %d\n" , y[i].no_producto,y[i].nom_producto,y[i].precio_menudeo,y[i].precio_mayoreo,y[i].personal);
		}
	}
	do
	{
		printf("\n1. Modificar catalogo de servicios.\n");
		printf("2. Buscar un servicio por su nombre. \n");
		printf("3. Salir. \n");
    	printf("Ingrese la opcion deseada\n");
    	scanf("%d",&opc);
        //printf("%d\n           kjdlajdalk", opc);
    	switch(opc)
    	{
    		case 1:Agregar(n,y);
            printf("dadadadasdas\n");
    			   guardarproductos(n,y);
    			   break;
    		case 2: mostrarservicio(n,y);
    				break;
    		case 3: 
    				printf("Salir");
    				break;
    		default: printf("Opcion incorrecta\n");
    				system("pause");
    	}
    }while(opc!=3);
	fclose(ap);
    system("pause");
}
void Agregar (int n, serv y[])
{
	
	char servicio[30];
	int i=0,ult=0,var=0;
	ap=fopen("servicios.txt","a");
	if(ap==NULL) 
	{
		printf("No se encontro el archivo");
	}
	else
	{
		for (i=0;i<n;i++)
     {
       		 y[i].no_producto=var+i;
        	 printf("%d",y[i].no_producto);
       		 printf("Ingresa el nombre del servicio: ");
       		 scanf("%s",&y[i].nom_producto);
        	 printf("Ingresa el precio del producto en menudeo: ");
       		 scanf("%f",&y[i].precio_menudeo);
        	 printf("Ingresa el precio del producto en mayoreo: ");
        	 scanf("%f",&y[i].precio_mayoreo);
        	 printf("Ingresa el personal que hay disponible para el servicio: ");
        	 scanf("%d",&y[i].personal);
        	 ult=var+i;
    }
    }
}
void guardarproductos (int n, serv y[])
{
    int i;
	for(i=0;i<n;i++)
    {
        
        fprintf(ap,"%d %s %f %f %d\n" , y[i].no_producto,y[i].nom_producto,y[i].precio_menudeo,y[i].precio_mayoreo,y[i].personal);
    }
} 
int mostrarservicio (int n, serv y[])
{
	//freopen("servicios","r",stdin);
	char nombre[30];
	int i;
	printf("Ingresa el servicio que deseas buscar:  ");
	scanf("%s",&nombre);
    cout<<nombre<<endl;
	for(int i=0;i<4;i++)
	{
			//cout<<y[i].nom_producto<<"  "<<nombre<<endl;
            string w(y[i].nom_producto);
            if(w==nombre)
			{
				
                printf("______________________________\n");
				printf("id: %d\n",y[i].no_producto);
            	printf("nombre: %s\n",y[i].nom_producto);
            	printf("precio menudeo: %f\n",y[i].precio_menudeo);
            	printf("Precio mayoreo: %f\n",y[i].precio_mayoreo);
            	printf("Personal: %d\n",y[i].personal);
            	printf("______________________________\n\n");
                break;
			}
	}
    if (i==5) printf("No encontrado\n");
	fclose(ap);
}
	
	




