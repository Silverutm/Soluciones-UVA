#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}

inline ll divmod(const ll &a, const ll &b)
{
	ll binv;
	ll y;
	ll m = mod;
	gcd(b, m, binv, y);

	binv = ((binv%m)+m)%m;

	return ( (a % m) * (binv % m) ) % m;
}

long long suma_cuadrados(long long k)
{
	//return (((k * (k+1) * (2 * k+1)) / 6) % mod);
	if (k&1)
	{
		if (k%3==0)
			return k/3%mod * ((k+1)/2%mod)%mod * ((2 * k+1)%mod)  % mod;
		if (k%3==1)
			return k%mod * ((k+1)/2%mod)%mod * ((2 * k+1)/3%mod)  % mod;

		return k%mod * ((k+1)/6%mod)%mod * ((2 * k+1)%mod)  % mod;


	}
	else
	{
		if (k%3==0)
			return k/6%mod * ((k+1)%mod)%mod * ((2 * k+1)%mod)  % mod;
		if (k%3==1)
			return k/2%mod * ((k+1)%mod)%mod * ((2 * k+1)/3%mod)  % mod;

		return k/2%mod * ((k+1)/3%mod)%mod * ((2 * k+1)%mod)  % mod;

		
	}
}

long long suma_sucesivos(long long k)
{
	//long long suma_suc = 0;
	//for (long long i = 1; i <= k; i++)
	//	suma_suc += i * (i+1);
	//suma_suc = (k)*(k+1)*((k+2)/3);
	
	if (k%3==0)
		return (k/3%mod)*((k+1)%mod)%mod*((k+2)%mod) % mod;
	else if (k%3==1)
		return (k%mod)*((k+1)/3%mod)%mod*((k+2)/3%mod) % mod;
	else
		return (k%mod)*((k+1)/3%mod)%mod*((k+2)%mod) % mod;
	//return ((k)*(k+1)*(k+2)/3) % 1000000007;
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	long long modulo = 1000000007;
	int iterador = 1;
	while(t--)
	{
		long long n;
		long long cuadros;
		long long sumaT;
		long long k;
		long long c_arriba;
		long long s_arriba;
		long long diferencia;
		long long s_abajo;
		long long suma_respuesta;
		long long cuadros1;
		long long suma1_arriba;

		//scanf("%lld", &n);
		cin>>n;
		//if (n % 2 != 0)
		if (n & 1)
		{

			cuadros = n%mod * ((n + 1) / 2 %mod) %mod;
			//cout << "cuadros " << cuadros << endl;
			sumaT = divmod(cuadros * ((cuadros + 1) % modulo), 2 ) ;
			//cout << "sumaT "<< sumaT << endl;
			k = n - (n + 1) / 2;
			//cout << "k " << k << endl;
			if (k&1)
				c_arriba = k%mod * ((k + 1)/2%mod)% modulo ;
			else
				c_arriba = k/2%mod * ((k + 1)%mod)% modulo ;
			//cout << "c_arriba " << c_arriba << endl;
			s_arriba = (c_arriba * ((c_arriba + 1) % modulo) / 2) ;
			//cout << "s_arriba " << s_arriba << endl;
			//cout << "suma_cuadrados " << suma_cuadrados(k) << endl;
			//cout << "suma_sucesivos " << suma_sucesivos(k) << endl;
			//s1 = (suma_cuadrados(k) + s_arriba) % modulo;
			////cout << "s1 " << s1 << endl;
			//s2 = (suma_sucesivos(k) + s1) % modulo; 
			////cout << "s2 " << s2 << endl;
			diferencia = 0;
			diferencia = (((suma_sucesivos(k) - suma_cuadrados(k))) + modulo) % modulo;
			//cout << "diferencia " << diferencia << endl;
			s_abajo = ((s_arriba % modulo) + suma_cuadrados(k)) % modulo;
			//cout << "s_abajo " << s_abajo << endl;
			if (k&1)
			{
				s_abajo += (suma_cuadrados(k)*k%modulo + diferencia*k%modulo*((k+1)/2)%modulo)%modulo;	
			}
			else 
				s_abajo += (suma_cuadrados(k)*k%modulo + diferencia*(k/2)%modulo*(k+1)%modulo)%modulo;
			
			/*for (int i = 1; i <= k; ++i)
			{
				s_abajo += (suma_cuadrados(k) + i * diferencia) % modulo;
				//cout << "s_abajo " << s_abajo << endl;

			}*/
			////cout << "s_abajo " << s_abajo << endl;
			suma_respuesta = (((sumaT - s_arriba + modulo) % modulo) - s_abajo + modulo) % modulo;
			//printf("Case #%d: %lld\n", iterador, suma_respuesta);
			cout<<"Case #"<<iterador<<": "<<suma_respuesta<<"\n";
		}
		else
		{
			cuadros = (n * (n + 1) / 2);
			//cout << "cuadros " << cuadros << endl;
			sumaT = (cuadros * (cuadros + 1) % modulo) / 2;
			//cout << "sumaT " << sumaT << endl;
			c_arriba = ((n/2)+1) * ((n/2)) /2;
			//cout << "c_arriba " << c_arriba << endl;
			s_arriba = (c_arriba * (c_arriba + 1) % modulo) / 2;
			//cout << "s_arriba " << s_arriba << endl;


			k = n / 2;
			
			cuadros1 = ((k-1) * k) / 2;
			suma1_arriba = (cuadros1 * (cuadros1 + 1)) % modulo / 2;

			//cout << "suma_cuadrados " << suma_cuadrados(k) << endl;
			//cout << "suma_sucesivos " << suma_sucesivos(k) << endl;
			
			//cout << "k " << k << endl;
			diferencia = (((suma_sucesivos(k-1) - suma_cuadrados(k-1))) + modulo) % modulo;
			//cout << "diferencia " << diferencia << endl;
			s_abajo = ((suma1_arriba % modulo) + suma_cuadrados(k-1)) % modulo;
			//cout << "s_abajo " << s_abajo << endl;
			
			//s_abajo += (suma_cuadrados(k-1)*k%modulo + k*(k+1)%modulo*diferencia%modulo)%modulo;
			if (k&1)
			{
				s_abajo += (suma_cuadrados(k-1)*k%modulo + diferencia*k%modulo*((k+1)/2)%modulo)%modulo;	
			}
			else 
				s_abajo += (suma_cuadrados(k-1)*k%modulo + diferencia*(k/2)%modulo*(k+1)%modulo)%modulo;
			/*for (int i = 1; i <= k; ++i)
			{
				s_abajo += (suma_cuadrados(k-1) + i * diferencia) % modulo;
				//cout << "s_abajo " << s_abajo << endl;

			}*/
			////cout << "s_abajo " << s_abajo << endl;
			suma_respuesta = (((((((sumaT - s_arriba) % modulo) + modulo) % modulo) - s_abajo) % modulo) + modulo) % modulo;
			//suma_respuesta = sumaT - s_arriba - s_abajo;
			//printf("Case #%d: %lld\n", iterador, suma_respuesta);
			cout<<"Case #"<<iterador<<": "<<suma_respuesta<<"\n";
			//printf("%lld\n", suma_respuesta);
		}
		iterador++;
	}
	return 0;
}