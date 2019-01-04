#include <bits/stdc++.h>
using namespace std;

main(){
	int T,n,p,q,k,pasotodo=1,m=1;
	vector<int> da,recibe;
	cin>>T;
	for(int i=0;i<T;i++)
    {
		cin>>n;
		da.clear();
		recibe.clear();
		pasotodo=1;
		m=1;
        for(int j=0;j<n;j++)
        {
			cin>>p>>q;
			da.push_back(p);
			recibe.push_back(q);
            if(p==q)
            {
				pasotodo=0;
			}
		}
		sort(da.begin(),da.end());
		sort(recibe.begin(),recibe.end());
		for(auto k: da){
			if(da[k-1]!=m){
				pasotodo=0;
			}	
			m++;
		}
		m=1;
		for(auto k: recibe){
			if(recibe[k-1]!=m){
				pasotodo=0;
			}
			m++;
		}
		if(pasotodo){
				cout<<"Intercambio exitoso."<<endl;
			}else{
				cout<<"Papelitos otra vez."<<endl;
			}
	}

}