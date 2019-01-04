#include<bits/stdc++.h>
using namespace std;
#define tam 105
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;



#define arr 0
#define der 2
#define aba 4
#define izq 6
int n, x, y, dir, sig, xs, ys;

void laotra()
{
    if (abs(x) == abs(y))
    {
        //dir = (dir + 6)%8;
        if (x>0 and y>0)
            {++x;return;}
        
    }
    
    if (dir == izq) --x;
    else if (dir == der) ++x;
    else if (dir == arr) --y;
    else ++y;
}

int main()
{
    
    cin>>n;    
    //------------2------------
    map<ii, int> mapa;
    mapa[ii{y,x}] = 1;

    ++x; dir = arr;
    while(mapa[ii{y,x}]<n)
    {
        if (abs(x) == abs(y))
        {
            dir = (dir + 6)%8;
            //if (x>0 and y>0)
            //    ++x;
        }
        
        
        //sig = (dir + 6)%8;
        //xs = x; ys = y;        
        /*while (mapa[ii{ys, xs}])
        {
            laotra();
        }*/
        //sacar la suma
        mapa[ii{y,x}]  = mapa[ii{y-1,x-1}] + mapa[ii{y-1,x}] + mapa[ii{y-1,x+1}] + mapa[ii{y,x-1}] +
                        mapa[ii{y,x+1}] + mapa[ii{y+1,x-1}] + mapa[ii{y+1,x}] + mapa[ii{y+1,x+1}];
        
        cout<<mapa[ii{y,x}]<<endl;
        if (mapa[ii{y,x}]>n)
            break;
        //x = xs; y = ys;
        //dir = sig;
        laotra();
    }
    cout<<mapa[ii{y,x}]<<endl;
    return 0;
}
