#include <iostrema>
#include <vector>
#include <set>
#include <queue>
using namespace std;
long long s;
vector <int> unos, ceros;
vector< <vector <int> > >subuno[12], subcero[12];
queue < vector <int> > cola;

void hacersubunos()
{
	while ( !cola.empty() )
	{
		auto v=cola.front();
		cola.pop();
		
	}
}

int main()
{
	int k, a, t;
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
		while (!cola.empty()) cola.pop();
		for (i=0;i<unos.size(); ++i)
		{
			comodin.push_back(i);
			cola.push( comdin )
			comodin.pop_back();
		}
		hacersubunos();

	}
	return 0;
}