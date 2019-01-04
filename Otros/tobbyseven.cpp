#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
long long s;
vector <int> unos, ceros;
vector < vector <int> > subuno[12], subcero[12];
queue < vector <int> > cola;
int t;
long long maxi ;
bool f (int i,int j) { return (i>j); }
void hacersubunos()
{
	while ( !cola.empty() )
	{
		auto v=cola.front();
		
		/*for (auto e:v)
			cout<<e<<" ";
		cout<<endl;*/

		
		cola.pop();
		subuno[ v.size() ].push_back(v);
		if ( v.size()==t ) continue;
		//auto copia=v;		
		for (int i=v.back()+1; i<unos.size(); ++i ) 
		{			
			v.push_back(i);
			cola.push(v);
			v.pop_back();
		}
	}
}


void hacersubceros()
{
	while ( !cola.empty() )
	{
		auto v=cola.front();
		
		cola.pop();
		subcero[ v.size() ].push_back(v);
		if ( v.size()==t ) continue;
		//auto copia=v;		
		for (int i=v.back()+1; i<ceros.size(); ++i ) 
		{
			v.push_back(i);
			cola.push(v);
			v.pop_back();
		}
	}
}

void pintarcero(vector <int> v, bool color)
{
	for (int i=0; i<v.size(); ++i)
		if (color)
			s |=(1<<ceros[ v[i] ]);	
		else
		s &= ~(1<<ceros[ v[i] ]);
}
void pintaruno(vector <int> v, bool color)
{
	for (int i=0; i<v.size(); ++i)
		if (color)
			s |= (1<<unos[ v[i] ]);	
		else
		s &= ~(1<<unos[ v[i] ]);
}
//bool boleano;
void verificar()
{
	if (s%7==0 )
	{
		if (s>maxi)
			maxi=s;
		//boleano=false;
	}
}

void revisar(int i)
{
	//long long copia=s;
	//boleano=true;
	for (auto v1: subcero[i] )
	{
		pintarcero(v1, true);
		for (auto v2: subuno[i])
		//for (auto v2=subce[i].rbegin(); itv!=subuno[i].rend(); ++itv)
		{
			pintaruno(v2, false);
			verificar();
			pintaruno(v2, true);
			//if (not boleano) break;
		}
		pintarcero(v1, false);
		//if (not boleano) break;
	}
	//printf("S: %lld\n", s);
}

int main()
{
	int k, a,i;
	while (scanf("%lld", &s)==1)
	{
		unos.clear();
		ceros.clear();
		scanf("%d", &k);	
		//listo=false;
		while (k--)
		{
			scanf("%d", &a);
			if ( s&(1LL<<a) ) unos.push_back(a);
			else ceros.push_back(a);
		}
		t=ceros.size()< unos.size() ? ceros.size():unos.size();
		//sub(t);
		vector <int> comodin;
		//sort(ceros.begin(),ceros.end(), f);
		//sort(unos.begin(),unos.end(), f);
		
		for (int j=1; j<=10; ++j)
		{
			subuno[j].clear();
			subcero[j].clear();
		}

		while ( !cola.empty() ) cola.pop();
		for (i=0;i<unos.size(); ++i)
		{
			comodin.push_back(i);
			cola.push( comodin );
			comodin.pop_back();
		}
		hacersubunos();

		while (!cola.empty()) cola.pop();
		for (i=0;i<ceros.size(); ++i)
		{
			comodin.push_back(i);
			cola.push( comodin );
			comodin.pop_back();
		}
		hacersubceros();

		/*
		cout<<"unos\n";
		for (auto ke: unos)
			cout<<ke<<" ";
		cout<<endl;
		cout<<"ceros\n";
		for (auto ke: ceros)
			cout<<ke<<" ";
		cout<<endl;*/
		/*
		cout<<"sub ceros\n";

		for (i=1; i<=t;++i)
			for ( auto v:subcero[i] )
			{
				cout<<v.size()<<":  ";
				for (auto e:v)
					cout<<ceros[ e ]<<" ";
				cout<<"\n";
			}
		cout<<"-----------\n";*/
		/*
		cout<<"sub unos\n";

		for (i=1; i<=t;++i)
			for (auto itv=subuno[i].rbegin(); itv!=subuno[i].rend(); ++itv)
			//for ( auto v:subuno[i] )
			{
				cout<<(*itv).size()<<":  ";
				for (auto e:*(itv) )
					cout<<unos[ e ]<<" ";
				cout<<"\n";
			}
		cout<<"-----------\n";
		*/
		maxi=0;
		if (s%7==0) maxi=s;
		for (i=1; i<=t; ++i)
			revisar(i);
		//cout <<"hoa\n";
		printf("%lld\n", maxi);
		//cout<<"afdsf\n";
	}
	return 0;
}