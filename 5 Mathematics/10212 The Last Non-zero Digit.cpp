#include <iostream>
using namespace std;
typedef long long ll;



int main()
{
    ll n, m, res, i;
    while (scanf("%lld %lld", &n, &m) == 2)
    {
        res = 1;
        i = 0;
        for( i = n - m + 1; i <= n; i++ )
        {
            res *= i;
            while (res%10==0)
                res /= 10;            
            res %= 1000000000;
        }
         printf("%lld\n", res%10);
    }
    return 0;
}