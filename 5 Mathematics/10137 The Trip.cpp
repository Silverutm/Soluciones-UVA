#include<bits/stdc++.h>
using namespace std;
double arreglo[1005];
int main()
{
    int a, c, n; char b;
    double prom, res, res2, suma;
    while (cin>>n and n)
    {
        res2 = res = suma = 0;
        for (int i=0; i< n; ++i)
        {
            //scanf("%d%c%d", &a, &b, &c);
            //areglo[i] = a*100 + c;
            scanf("%lf", &arreglo[i]);
            suma += arreglo[i];
        }
        prom = suma / n;
        //printf("%d\n", prom);
        for (int i=0; i< n; ++i)
            if (arreglo[i]> prom)
                res += (double) (long) ((arreglo[i]-prom) * 100.0) / 100.0;
            else res2 += (double) (long) ((-arreglo[i]+prom) * 100.0) / 100.0;
        //printf("%d\n", res);
        //printf("%d\n", res2);
        res = max(res, res2);
        printf("$%.2lf\n", res);
        //int res3 = int(res);
        
        //printf("$%d.%d%d\n", res3/100, (res3%100 - res3%10)/10, res3%10  )  ;
    }
    return 0;
}