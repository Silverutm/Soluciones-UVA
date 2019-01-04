#include <bits/stdc++.h>
#define MAX 100000000
typedef long long ll;
using namespace std;

map <ll,bool> mapa;
vector <ll> res;

bool es_primo(ll x) {
	ll raiz=sqrt(x);
	if(x%2==0) return false;
	for(ll i=3;i<=raiz;i+=2) 
		if(x%i==0)
			return false;
	return true;
}

ll alreves(ll x) {
	ll w=0;
	while(x>0) {
		w*=10;
		w+=(x%10);
		x/=10;
	}
	return w;
}

void precalculo() {
	mapa[2]=1; mapa[3]=1;
	mapa[5]=1; mapa[7]=1;
	ll x,j,tama,aux;
	map <ll,bool>::iterator act=mapa.begin();
	while(act->first<MAX) {
		x=act->first;
		tama=0;
		while(pow(10,tama)<=x) tama++;
		for(j=1;j<10;j++) {
			aux=j*pow(10,tama)+x;
			if(es_primo(aux))
				mapa[aux]=1;
		}
		act++;
	}
}

int main() {
	precalculo();
	for(map<ll,bool>::iterator it=mapa.begin();it!=mapa.end();it++)
		if(mapa.count(alreves(it->first)))
			res.push_back(it->first);
	int T;
	ll a,b,c,d;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld %lld",&a,&b);
		d=c=0;
		while(c<res.size()) {
			if(a<=res[c] && res[c]<=b)
				d++;
			c++;
		}
		printf("%lld\n",d);
	}
}