#include <bits/stdc++.h>
using namespace std;
#define tam 100005

int arr[tam];
int main()
{
    int n, cero = 0, i;
    scanf("%d", &n);
    for ( i = 1; i<=n; ++i)
    {
        scanf("%d", &arr[i]);
        cero += arr[i] == 0;
    }
    
    if (cero == n) {printf("0\n"); return 0;}


    bool baja = true;
    int mont = 0;
    for ( i = 1; i<=n; ++i)
    {
        if (baja)
        {

        }
        else //subo
    }
    return 0;
}