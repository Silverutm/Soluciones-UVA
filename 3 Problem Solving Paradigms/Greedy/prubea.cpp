#include <iostream>
#include <vector>
using namespace std;
typedef vector <int > vi;
vi v, cosa;

int elemento=10;;
bool busqueda(int ini,int  fin)
{
	int mitad=(ini+fin)/2;
	if (v[mitad]>=elemento) return true;
	if (ini==fin) return false;
	if (v[mitad]<elemento)
		return busqueda(mitad+1, fin);
	return busqueda(ini, mitad-1);
}

vi combinar(vi L1, vi L2)
{
	vi respuesta;
	int i=0, j=0;
	while ( i<L1.size() and j<L2.size() )
	{
		if ( L1[i]<L2[j] )
		{
			respuesta.push_back(L1[i]);
			++i;
		}
		else 
		{
			respuesta.push_back(L2[j]);
			++j;
		}
	}
	if ( i==L1.size() )
		for (; j<L2.size(); ++j)
			respuesta.push_back(L2[j]);
	else 
		for (; i<L1.size(); ++i)
			respuesta.push_back(L1[i]);
	return respuesta;
}

vi mergesort(vi L)
{
	if (L.size()==1)
		return L;
	vi v1(L.begin(), L.begin()+L.size()/2 );
	vi v2( L.begin()+L.size()/2, L.end() );
	vi L1 = mergesort(v1);
	vi L2 = mergesort(v2);
	return combinar(L1, L2);
}

int main()
{
	
	for (int i=0; i<2; ++i)
		v.push_back(i*i);
	//int i=4;
	//cosa.assign(v.begin(), v.begin()+4 );
	//for (auto c:cosa)
	//	cout <<c<<" ";
	vi orden=mergesort(v);
	for (auto c:orden)
		cout<<c<<endl;
	//if ( busqueda(0, 9) ) cout<<"cool\n";
	//else cout<<"not cool\n";
	return 0;
}