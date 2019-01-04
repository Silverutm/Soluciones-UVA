#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
char matriz[25][25];
int i, j;

void alfil()
{
	//cout<<"alfil\n";
	int w=i, z=j;
	while (not isalpha(matriz[++w][++z]) ) matriz[w][z]='*';
	w=i; z=j;
	while ( not isalpha(matriz[++w][--z]) ) matriz[w][z]='*';
	w=i; z=j;
	while (not isalpha(matriz[--w][--z]) ) matriz[w][z]='*';
	w=i; z=j;
	while (not isalpha(matriz[--w][++z]) ) matriz[w][z]='*';
}


void torre()
{
	int w=i, z=j;
	while (not isalpha(matriz[++w][z]) ) matriz[w][z]='*';
	w=i; z=j;
	while (not isalpha(matriz[--w][z]) ) matriz[w][z]='*';
	w=i; z=j;
	while (not isalpha(matriz[w][--z]) ) matriz[w][z]='*';
	w=i; z=j;
	while (not isalpha(matriz[w][++z]) ) matriz[w][z]='*';
}
int cx[]={1,2,2,1,-1,-2,-2,-1};
int cy[]={-2,-1,1,2,2,1,-1,-2};

void caballo()
{
	//cout<<"aqui\n";
	for (int k=0; k<8; ++k)
	if ( not isalpha( matriz[i+cx[k]][j+cy[k]] ) ) 
		matriz[i+cx[k]][j+cy[k]]='*';
}

void ataque(char pieza)
{
	if (not isalpha(pieza)) return;
	//cout<<"holaqqqqqqq\n";
	//cout<<pieza;
	int w, z;
	if (pieza=='k' or pieza=='K')
	{	
		for ( w=i-1; w<=i+1; ++w) 
			for ( z=j-1; z<=j+1; ++z) 
				if (not isalpha(matriz[w][z]) )
					matriz[w][z]='*';
	}
	else if (pieza=='b' or pieza=='B')
	{ alfil(); }
	else if (pieza=='r' or pieza=='R')
	{	torre(); }
	else if (pieza=='q' or pieza=='Q')
		{ alfil(); torre(); }
	else caballo();
}

void peon(char p)
{
	//cout<<p;
	if (p=='p')
	{
		if ( not isalpha(matriz[i+1][j+1]) )matriz[i+1][j+1]='*';
		if (not isalpha( matriz[i+1][j-1])) matriz[i+1][j-1]='*';
	}
	else 
	{
		if ( not isalpha( matriz[i-1][j+1]))matriz[i-1][j+1]='*';
		if (not isalpha(matriz[i-1][j-1]))matriz[i-1][j-1]='*';
	}
}

int main()
{
	string s;
	int res;
	while ( cin>>s )
	{	
		memset (matriz, 0, sizeof matriz);
		for (i=10; i<=19; ++i)
			matriz[10][i]=matriz[i][10]=matriz[19][i]=matriz[i][19]='z';
		i=11; j=11;

		for (auto c: s)
		{
			if (c=='/') continue;//
			else if ( isalpha(c) )
			{
				matriz[i][j]=c;
				++j;
				//if (j==19) { ++i; j=11; }
			}
			else j += c-'0';
			if (j==19) { ++i; j=11; }
		}
		for (i=11; i<=18; ++i)
			for (j=11; j<=18; ++j)
				if (matriz[i][j]!='p' and matriz[i][j]!='P')
					ataque( matriz[i][j] );
				else peon( matriz[i][j] );
		res=0;
		for (i=11; i<=18; ++i)
			for (j=11; j<=18; ++j)
				if (matriz[i][j]==0) ++res;
		cout<<res<<endl;
/*
		for (i=11; i<=18; ++i, cout<<endl)
			for (j=11; j<=18; ++j)
				if (matriz[i][j]==0) cout<<".";
				else cout<<matriz[i][j];*/
	}
	return 0;
}
