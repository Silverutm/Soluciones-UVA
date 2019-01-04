#include<bits/stdc++.h>
using namespace std;
#define tam 1505
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//#define first first
//#define second x
map<ii, int> mapa;
int x[] = {0,   3, 3, 0, -3, -3};
int y[] = {-2, -1, 1, 2,  1, -1};
int main()
{        
    

    ii cor{0,0};
    mapa[cor] = 1;
    queue <ii> cola;
    cola.push(cor);
    while( mapa[cola.front()] <=1500 )
    {
        cor = cola.front(); cola.pop();
        for (int i = 0; i<6; ++i)
        {
            auto par = ii{cor.first + y[i], cor.second + x[i]}; 
            if (mapa[par] == 0)
            {
                cola.push(par);
                mapa[par] = mapa[cor] + 1;
            }
        }

    }
    
    string ins;
    cor = ii{0,0};
    int maxi = 0;
    while (cin>>ins)
    {
        if (ins=="n")
            cor.first += -2;
        else if (ins == "ne")
        {
            cor.first += -1;
            cor.second += 3;
        }
        else if (ins == "se")
        {
            cor.first += 1;
            cor.second += 3;
        }
        else if (ins=="s")
            cor.first += 2;
        else if (ins == "sw")
        {
            cor.first += 1;
            cor.second += -3;
        }
        else if (ins == "nw")
        {
            cor.first += -1;
            cor.second += -3;
        }
        //------------2------------
        maxi = max(maxi, mapa[cor]);
    }
    //------------1------------
    cout<<mapa[cor] - 1 <<endl;
    cout<<maxi - 1 <<endl;
    return 0;
}
