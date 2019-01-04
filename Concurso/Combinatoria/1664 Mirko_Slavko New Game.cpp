#include <bits/stdc++.h>
using namespace std;
#define tam 101
int n, a[tam], b[tam], ca[tam], cb[tam];

int main()
{
    int i, res, x, y, mi;    
    a[0] = b[0] = 1;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &x, &y);
        a[x]++; b[y]++;
        for (i=-1; ++i<101; ca[i]=a[i], cb[i]=b[i]);

        x = 100; y = 1;
        res = 0;        
        while(1)
        {
            while (not ca[x]) --x;
            if (x==0) break;
            while (not cb[y]) ++y;
            

            mi = min(ca[x], cb[y]);
            ca[x] -= mi; cb[y] -= mi;
            //cout<<x<<"  "<<y<<endl;
            res = max(res, x + y);
        }
        printf("%d\n",res);
    }
    return 0;   
}