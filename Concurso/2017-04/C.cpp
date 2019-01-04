#include <bits/stdc++.h>
using namespace std;
#define tam 500007
typedef vector <int> vi;
typedef long long ll;
ll h[tam], x[tam], izq[tam], i_izq[tam];
double res_izq[tam];

ll der[tam], i_der[tam];
double res_der[tam];

int con_der[tam], con_izq[tam];
int main()
{
	int n, i, lim, j;
	while (cin>>n)
	{
		n += 2;
		for ( i = 0; i < n; ++i)
			cin>>x[i]>>h[i];					

		izq[n] = h[0]; lim = n; i_izq[n] = 0;
		for ( i = 1; i < n - 1; ++i)
		{
			j = upper_bound(izq + lim, izq + n + 1, h[i]) - izq;
			res_izq[i] = hypot(x[i] - x[ i_izq[j] ], h[ i_izq[j] ] - h[i]  );
			con_izq[i] = i_izq[j];

			izq[j-1] = h[i];
			i_izq[j-1] = i;
			lim = j - 1;

			//cout<<con_izq[i]<<" "<<res_izq[i]<<endl;
		}

		der[n] = h[0]; lim = n; i_der[n] = 0;
		for ( i = 0; i < n/2; ++i)
		{
			swap(x[i], x[n-i-1]);
			swap(h[i], h[n-i-1]);
		}
		for ( i = 1; i < n - 1; ++i)
		{
			j = upper_bound(der + lim, der + n + 1, h[i]) - der;
			res_der[i] = hypot(abs(x[i] - x[ i_der[j] ]), abs(h[ i_der[j] ] - h[i])  );
			con_der[i] = i_der[j];

			der[j-1] = h[i];
			i_der[j-1] = i;
			lim = j - 1;

			//cout<<con_der[i]<<" "<<res_der[i]<<endl;
		}
		for ( i = 1; i < n - 1; ++i)
		{
			//cout<<con_izq[i]<<" "<<n-1-con_der[i]<<" "<<res_izq[i]<<" "<<res_der[n-i]<<"\n";
			printf("%d %d %.4lf %.4lf\n", con_izq[i],n-1-con_der[i],res_izq[i],res_der[n-i]);
		}
	}
	return 0;
}