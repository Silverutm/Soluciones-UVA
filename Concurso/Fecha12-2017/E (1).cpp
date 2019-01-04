#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

string s;
vi es;
vector <string> cadenas;
vi numeros;

int main()
{
    string s, p;
    while (getline(cin, p) and p[0]!='.')
    {
        cadenas.clear(); numeros.clear(); es.clear();
        stringstream ss(p);
        while (ss>>s)
        {
            s.pop_back();
            //cout<<s<<endl;
            if ((s[0]>='0' and s[0]<='9') or s[0]=='-')
            {
                stringstream cc(s);
                int x; cc>>x;
                numeros.push_back(x);
                es.push_back(1);
            }
            else
            {
                cadenas.push_back(s);
                es.push_back(0);
            }
        }   

        //cout<<es.size()<<"  "<<cadenas.size()<<"  "<<numeros.size()<<"\n";
        sort(numeros.begin(), numeros.end());
        sort(cadenas.begin(), cadenas.end());
        int k = 0, l = 0, i;
        for (i=0; i<es.size() - 1; ++i)
        {
            if (es[i])
                cout<<numeros[k++];
            else cout<<cadenas[l++];
            cout<<", ";
        }
        if (es[i])
            cout<<numeros[k++];
        else cout<<cadenas[l++];
        cout<<".\n";
    }
}