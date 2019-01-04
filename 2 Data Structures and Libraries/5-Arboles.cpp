#include<iostream>
#include<cstdlib>
using namespace std;

struct Raiz
{
	char info;
	struct Raiz *derecha;
	struct Raiz *izquierda;
};

Raiz *p ,*q;
char Abuscar;

void Carga(Raiz *r)
{
	system("cls");
	int hayizq=0,hayder=0;
	cout<<"Raiz:\n";
	cin>>r->info;
	cout<<"Si hay hijo izquierdo en "<<r->info<< " inserta un 1, si no, cualquier otro  \n";
	cin>>hayizq;
	if(hayizq==1)
	{
		q=new Raiz;
		r->izquierda=q;
		Carga(q);
	}
	else
	{
		r->izquierda=NULL;
	}
	cout<<"Si hay hijo derecho en "<<r->info<< " inserta un 1, si no, cualquier otro  \n";
	cin>>hayder;
	if(hayder==1)
	{
		q=new Raiz;
		r->derecha=q;
		Carga(q);
	}
	else
	{
		r->derecha=NULL;
	}
}

void BorraArbol(Raiz *r)
{
	if(r!=NULL)
	{
		BorraArbol(r->izquierda);
		BorraArbol(r->derecha);
		r->izquierda=NULL;
		r->derecha=NULL;
		delete(r);
		r=NULL;
	}
}
void Buscar(Raiz *r,char Abuscar)
{
	if(r!=NULL)
	{
		if(r->info!=Abuscar)
		{
			Buscar(r->izquierda,Abuscar);
			Buscar(r->derecha,Abuscar);
		}
		else if(r->info==Abuscar)
		{	
			cout<<"Se encontro el elemento "<<r->info<<endl;
			system("pause");
		}
		else
		{
			cout<<"El elemento no existe\n";	
		}
	}
}
void PreOrden(Raiz *r)
{
	if(r!=NULL)
	{
		cout<<r->info;
		PreOrden(r->izquierda);
		PreOrden(r->derecha);	
	}
}
void PosOrden(Raiz *r)
{
	if(r!=NULL)
	{
		PosOrden(r->izquierda);
		PosOrden(r->derecha);
		cout<<r->info;	
	}	
}
void InOrden(Raiz *r)
{
	if(r!=NULL)
	{
		InOrden(r->izquierda);
		cout<<r->info;
		InOrden(r->derecha);	
	}
}
int main()
{
	system("cls");
	int opcion;
	bool CreacionDeArbolAnterior=0;
	do
	{
		system("cls");
		cout<<"1-Crear Arbol\n";
		cout<<"2-Recorrido en preorden\n";
		cout<<"3-Recorrido en inorden \n";
		cout<<"4-Recorrido en posorden\n";
		cout<<"5-Buscar un elemento\n";
		cout<<"6-Eliminar un elemento\n";
		cout<<"7-Regresar\n";
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				if(CreacionDeArbolAnterior==0)
				{
					system("cls");
					char hayraiz;
					cout<<"Hay raiz en el arbol?:\t[s=si]\n";
					cin>>hayraiz;
					if(hayraiz=='s' or hayraiz=='S')
					{
						p=new Raiz;
						Carga(p);
					}
					CreacionDeArbolAnterior=1;
				}
				else
				{
					system("cls");
					BorraArbol(p);
					char hayraiz;
					cout<<"Hay raiz en el arbol?:\t[s=si]\n";
					cin>>hayraiz;
					if(hayraiz=='s' or hayraiz=='S')
					{
						p=new Raiz;
						Carga(p);
					}
				}
				break;
									
			case 2:
					if(p==NULL)
					{
						cout<<"No existe un arbol:\n";
						system("pause");
					}
					else
					{
						PreOrden(p);
						cout<<endl;
						system("pause");
					}
				break;
										
			case 3:
					if(p==NULL)
					{
						cout<<"No existe un arbol:\n";
						system("pause");
					}
					else
					{
						InOrden(p);
						cout<<endl;
						system("pause");
					}
				break;
										
			case 4:
					if(p==NULL)
					{
						cout<<"No existe un arbol:\n";
						system("pause");
					}
					else
					{
						PosOrden(p);
						cout<<endl;
						system("pause");
					}
				break;
			
			case 5:
					if(p==NULL)
					{
						cout<<"No existe un arbol:\n";
						system("pause");
					}
					else
					{
						cout<<"Elemento a buscar: \n";
						cin>>Abuscar;
						Buscar(p,Abuscar);
					}
				break;
										
			case 6:
					BorraArbol(p);
					
				break;
		}
	}while(opcion!=7);
	if(p!=NULL)
	{
		BorraArbol(p);
	}
}
A4:7A:A4:67:BC:1D
