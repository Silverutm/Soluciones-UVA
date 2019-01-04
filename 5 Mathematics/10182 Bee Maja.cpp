#include <bits/stdc++.h>
using namespace std;
#define tam 100005
#define ab_iz 0
#define ar_iz 1
#define ar 2
#define ar_der 3
#define ab_der 4
#define ab 5
int xx[tam], yy[tam], x, y, v, pared, pos, dir;

void siguiente()
{
    if (dir == ab_iz)
        --x, ++y;
    else if (dir == ar_iz)
        --x;
    else if (dir == ar)
        --y;
    else if (dir == ar_der)
        ++x, --y;
    else if (dir == ab_der)
        ++x;
    else if (dir == ab)
        ++y;
}

int main()
{
    xx[1] = yy[1] = 0;
    v = 2;
    x = 0; y = 1;
    pared = 2;
    pos = 2; dir = ab_iz;
    while (v<=tam)
    {
        xx[v] = x; yy[v] = y;
        if (pos == pared)
        {
            dir = (dir + 1)%6;
            pos = 1;    //estoy en pos 1 de la nueva direccion
        }
        if (pos==1 and dir == ab_iz)
        {
            pos = 2;
            ++pared;
            ++y;
        }
        else
        { 
            //avanzar
            ++pos;
            siguiente();        
        }
        ++v;   
    }

    while(cin>>v)
        cout<<xx[v]<<" "<<yy[v]<<"\n";
    return 0;
}