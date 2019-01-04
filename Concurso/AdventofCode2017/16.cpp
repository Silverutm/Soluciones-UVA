#include<bits/stdc++.h>
using namespace std;
#define tam 20
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{        
    //------------1------------
    int i, j, x, h[tam], h2[tam];
    string arr="abcdefghijklmnop";
    //for (i = 0; i < 16; ++i)
      //  arr[i] = 'a' + i;
    
    char ins, a, b;
    string s;
    getline(cin, s);
    
    map<string, int> mapa;
    int conta=0;
    mapa[arr] = ++conta;

    for (int kk=0; kk<1000000; ++kk)
    {
        stringstream ss(s);
        while(ss>>ins)
        {
            if (ins == 'x')
            {
                ss>>i>>j;
                swap(arr[i], arr[j]);
            }
            else if (ins == 'p')
            {
                ss>>a>>b;
                i = 0; while(arr[i]!=a) ++i;
                j = 0; while(arr[j]!=b) ++j;
                swap(arr[i], arr[j]);
            }
            else
            {
                ss>>x;
                for (i=0; i<x; ++i)
                    h[i] = arr[16 - x + i];
                for (i = 0; i< 16 - x; ++i)
                    h2[i] = arr[i];

                for (i=0; i<x; ++i)
                    arr[i] = h[i];
                for (i = 0; i< 16 - x; ++i)
                    arr[x + i] = h2[i];
            }
        }

        if(mapa[arr]) 
        {
            cout<<mapa[arr]<<endl;
            cout<<kk<<endl;
            break;
        }
        else mapa[arr] = ++conta;
    }
    

    for (i=0; i<16; ++i)
        printf("%c", arr[i]);
    cout<<"\n";
    return 0;
}
