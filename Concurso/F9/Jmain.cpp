#include <bits/stdc++.h>
using namespace std;

int arr[502];
int memo[502][252];
int visi[502][252];
int abc;

int dp(int pos,int rest) {
    if(rest==0)
        return arr[pos];
    if(visi[pos][rest]==abc)
        return memo[pos][rest];
    int mejor=0,aux,aux2;
    for(int i=pos-1;i>0;i--) {
        if(i==1)
            aux2=1;
        else
            aux2=i/2;
        aux=min(rest,aux2)-1;
        mejor=max(mejor,dp(i,aux));
    }
    memo[pos][rest]=mejor;
    visi[pos][rest]=abc;
    return mejor;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int W,N;
	cin>>W;
	for(abc=1;abc<=W;abc++) {
        cin>>N;
        for(int i=1;i<=N;i++)
            cin>>arr[i];
        cout<<"Spree #"<<abc<<": ";
        int mejor=0,aux;
        for(int i=N;i>1;i--) {
            if(i==1)
                aux=1;
            else
                aux=i/2;
            mejor=max(mejor,dp(i,aux-1)+arr[i]);
        }
        mejor=max(mejor,arr[1]);
        cout<<mejor<<"\n";
    }
	return 0;
}
