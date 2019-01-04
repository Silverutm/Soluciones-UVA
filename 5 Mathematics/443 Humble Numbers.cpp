#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
ll arreglo[5844];
ll dos[60], tres[60], cinco[60], siete[60];

int main()
{
    ll lim = 2000000000LL;
    dos[0] = tres[0] = cinco[0] = siete[0] = 1;
    int i;
    i = 1; while (dos[i-1]<lim) {dos[i] = dos[i-1]*2; ++i; }
    i = 1; while (tres[i-1]<lim) {tres[i] = tres[i-1]*3; ++i; }
    i = 1; while (cinco[i-1]<lim) {cinco[i] = cinco[i-1]*5; ++i; }
    i = 1; while (siete[i-1]<lim) {siete[i] = siete[i-1]*7; ++i; }
    
    int w=0;
    for (int i = 0; i<35; ++i)
    for (int j = 0; j<35; ++j)
    for (int k = 0; k<35; ++k)
    for (int l = 0; l<35; ++l)
        if (dos[i] and tres[j] and cinco[k] and siete[l])
            if (dos[i]*tres[j]<=lim)
            if (dos[i]*tres[j]*cinco[k]<=lim)
            if (dos[i]*tres[j]*cinco[k]*siete[l]<=lim)
                arreglo[w++] = dos[i]*tres[j]*cinco[k]*siete[l];

    sort(arreglo,arreglo+w);

    int n;    
    while (cin>>n and n)
    {
        string cad="th";
        if (n%100 >=10 and n%100<=20) cad="th";
        else if (n%10==1 ) cad="st";
        else if (n%10==2 ) cad="nd";
        else if (n%10==3 ) cad="rd";
        else if (n%10==4 ) cad="th";
        cout<<"The "<<n<<cad<<" humble number is "<<arreglo[n - 1]<<".\n";
    }        
    return 0;
}