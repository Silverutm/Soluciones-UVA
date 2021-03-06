#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
/*
Programa hecho por Moroni Silverio Flores :D
*/
/*
NumPer y NumSub empiezan en 1;
*/
map <int *, int> mapita;
int NumPer; //Numero de Personas
long long NumSub;
char Personas[100][4]; //100 personas, 4 materias
char Subconjuntos134 [4][1400];
int i, j, k, l, w;
int MaXFelicidad;	//felicidad
int F1, F2, F3;		//felicidad contra cada subconjunto
int FelConjunto;
string materias[]={"","1.Elem. de finanzas e Inv.", "2.Admin. de Sit. de Conta.", "3.Metodos variacionales", "4.Sistemas Dinamicos",
	 "5.Temas Sel. Mate.", "6.Graf. por Computadora", "7. Sistemas inteligentes", "8. Analisis d Algoritmos", "9.Simulacion esto.", "10. Temas Sel. de Esta.",
	  "11.Analisis de Des. y Teo. Juegos ", "12.Sist. operativos", "13. Prog. Multimed ", "14.Admin BD", "15.Temas S. de Compu."};
string s0, s1, s2, s3;
string e="    ";
int cuatro, tres, dos, comodin;

char arregloi[16], arregloj[16], arreglok[16];

//las funciones pinta me dicen que materias estan en cierto bloque te 4
// para ver que felicidad le daran a cada persona
//los despinto(0) para reutilizarlos despues
void pintai(bool a)
{
	arregloi[ Subconjuntos134[0][i] ]=a;
	arregloi[ Subconjuntos134[1][i] ]=a;
	arregloi[ Subconjuntos134[2][i] ]=a;
	arregloi[ Subconjuntos134[3][i] ]=a;
	return;
}
void pintaj(bool a)
{
	arregloj[ Subconjuntos134[0][j] ]=a;
	arregloj[ Subconjuntos134[1][j] ]=a;
	arregloj[ Subconjuntos134[2][j] ]=a;
	arregloj[ Subconjuntos134[3][j] ]=a;
	return;
}
void pintak(bool a)
{
	arreglok[ Subconjuntos134[0][k] ]=a;
	arreglok[ Subconjuntos134[1][k] ]=a;
	arreglok[ Subconjuntos134[2][k] ]=a;
	arreglok[ Subconjuntos134[3][k] ]=a;
	return;
}

void imprimeconjunto()
{
	printf("Felicidad %d\n", MaXFelicidad);
	printf("Personas %d\n4: %d     3: %d     2:%d\n",NumPer, cuatro, tres, dos );
	printf("Porcentaje %f\n", (float)MaXFelicidad/(4*NumPer) );
	s0=materias[ Subconjuntos134[0][i] ], s1=materias[ Subconjuntos134[1][i] ];
	s2=materias[ Subconjuntos134[2][i] ], s3=materias[ Subconjuntos134[3][i] ];
	cout<<s0<< e << s1 << e << s2 << e << s3 <<"\n";
	//printf("%s %s %s %s\n", s0, s1, s2, s3 );

	s0=materias[ Subconjuntos134[0][j] ], s1=materias[ Subconjuntos134[1][j] ];
	s2=materias[ Subconjuntos134[2][j] ], s3=materias[ Subconjuntos134[3][j] ];
	cout<<s0<< e << s1 << e << s2 << e << s3 <<"\n";

	s0=materias[ Subconjuntos134[0][k] ], s1=materias[ Subconjuntos134[1][k] ];
	s2=materias[ Subconjuntos134[2][k] ], s3=materias[ Subconjuntos134[3][k] ];
	cout<<s0<< e << s1 << e << s2 << e << s3 <<"\n";

	printf("\n");
}

//devuelve el mayor de dos numeros
int mayor(int a, int b)
{	return a>b ? a:b; }

void calcularfelicidad()
{
	FelConjunto=0; //es la felicidad que una tercia de bloques le dara a todas las personas
	cuatro=tres=dos=0;
	for (l = 0; ++l <= NumPer; )
	{
		//comparar persona l
		F1=F2=F3=0; //la felicidad que le da cada bloque a la persona l
		for (w=-1; ++w<4;)
		{
			if ( arregloi[ Personas[l][w]  ]==1) ++F1;  //contra i
			
			
		}
		for (w=-1; ++w<4;)
			if ( arregloj[ Personas[l][w]  ]==1) ++F2;  //contra j
		
		for (w=-1; ++w<4;)
			if ( arreglok[ Personas[l][w]  ]==1) ++F3;  //contra j

		comodin = mayor(F1, mayor( F2, F3) );
		FelConjunto += comodin;
		if (comodin==4) ++cuatro;
		else if (comodin==3) ++tres;
		else if (comodin==2) ++dos;
	}
	//si la felicidad de la tercia es mayor a la maxima hasta el momento
	if (FelConjunto>=MaXFelicidad)
	{
		MaXFelicidad=FelConjunto;
		imprimeconjunto();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	//freopen ("resultados.out","w",stdout);
	//freopen ("votos.in","r",stdin);
	for(w=-1;++w<=15;arregloi[w]=arregloj[w]=arreglok[w]=0);
	//Pedir todos los datos
	NumPer=0;
	//cout<<NumPer;
	while ( scanf("%d %d %d %d", &Personas[NumPer][0], &Personas[NumPer][1], &Personas[NumPer][2], &Personas[NumPer][3] )==4 )
		++NumPer;
	//cout<<"Hola"<<NumPer;
	//crear todos los sub{} de tamaño 4 de un conjunto de tamaño 13
	//Todos los bloques posibles
	NumSub=0;
	for (i=0; ++i<=15; )
		for (j=i; ++j<=15; )
			for (k=j; ++k<=15; )
				for (l=k; ++l<=15; )
				{
					++NumSub;
					Subconjuntos134[0][NumSub]=i;
					Subconjuntos134[1][NumSub]=j;
					Subconjuntos134[2][NumSub]=k;
					Subconjuntos134[3][NumSub]=l;
				}

	MaXFelicidad=0;
	//obtener todos los subconjuntos de tamaño 3, y evaluar cada uno contra todas las personas.
	//Todas las combinaciones de 3 de bloques posibles
	for (i=0; ++i<=NumSub; pintai(0) )
	{
		pintai(1);
		for (j=i; ++j<=NumSub; pintaj(0) )
		{
			pintaj(1);
			for (k=j; ++k<=NumSub; pintak(0) )
			{

				pintak(1);
				calcularfelicidad();	//i,j,k son los indices de las matrices
			}
		}
	}


	//fclose(stdout);
	//fclose(stdin);
	return 0;
}
