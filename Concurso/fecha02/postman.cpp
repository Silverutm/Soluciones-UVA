#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	long long xi, mi;
	bool flag = 0;
	vector <pair <long long, long long>> entregas_negativas;
	vector <pair <long long, long long>> entregas_positivas;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &xi, &mi);
		xi < 0 ? entregas_negativas.push_back(make_pair(abs(xi), mi)) : entregas_positivas.push_back(make_pair(xi, mi));
	}
	sort(entregas_positivas.begin(), entregas_positivas.end());
	sort(entregas_negativas.begin(), entregas_negativas.end());

	long long respuesta = 0;
	long long suma = 0;
	long long tiempo = 0;
	long long num_viajes = 0;
	int auxi = 0;
	bool flag1 = false;
	bool flag2 = false;
	long long suma_total_pos = 0, suma_total_neg = 0;




	if (!entregas_positivas.empty())
	{

		for (int i = 0; i < entregas_positivas.size(); ++i)
	{
		suma_total_pos += entregas_positivas[i].second;
	}
		if (suma_total_pos <= k)
		{
			respuesta += 2 * entregas_positivas[entregas_positivas.size() - 1].first; 
			flag1 = true;
		}

		if (!flag1)
		{
			for (int i = 0; i < entregas_positivas.size(); ++i)
			{
				if (suma + entregas_positivas[i].second <= k)
				{
					suma += entregas_positivas[i].second;
					tiempo = entregas_positivas[i].first;
				}
				else
				{
					if (entregas_positivas[i].second > k)
					{
						num_viajes = entregas_positivas[i].second / k;
						if (entregas_positivas[i].second % k != 0) num_viajes++;
						tiempo = entregas_positivas[i].first;
						respuesta += 2 * tiempo * num_viajes;
						flag = 0;
					}
					else 
					{
						i--;
						respuesta += 2 * tiempo;
						flag = 1;
					}
					suma = 0;
				}

			}
			flag ? respuesta += 2 * tiempo : false;
		}

	
	}
	suma = 0;
	flag = 0;
	if (!entregas_negativas.empty())
	{

	for (int i = 0; i < entregas_negativas.size(); ++i)
	{
		suma_total_neg += entregas_negativas[i].second;
	}
	
		if (suma_total_neg<= k)
		{
			respuesta += 2 * entregas_negativas[entregas_negativas.size() - 1].first; 
			flag2 = true;
		}

		if (!flag2)
		{
			for (int i = 0; i < entregas_negativas.size(); ++i)
			{
				if (suma + entregas_negativas[i].second <= k)
				{
					suma += entregas_negativas[i].second;
					tiempo = entregas_negativas[i].first;
				}
				else
				{
					if (entregas_negativas[i].second > k)
					{
						num_viajes = entregas_negativas[i].second / k;
						if (entregas_negativas[i].second % k != 0) num_viajes++;
						tiempo = entregas_negativas[i].first;
						respuesta += 2 * tiempo * num_viajes;
						flag = 0;
					}
					else 
					{
						i--;
						respuesta += 2 * tiempo;
						flag = 1;
					}
					suma = 0;
				}
			}
			flag ? respuesta += 2 * tiempo : false;
		}
		
	}
	printf("%lld\n", respuesta);
	return 0;
}