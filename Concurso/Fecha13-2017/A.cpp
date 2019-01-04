#include <bits/stdc++.h>
using namespace std;
#define tam 1005

int arr[tam], dif[tam];
int main()
{
    int n, i;
    while (scanf("%d", &n) == 1)
    {
        for (i = 0; i<n; ++i)
            scanf("%d", &arr[i]);
        for (i = 1; i<n; ++i)
            dif[i] = arr[i] - arr[i - 1];
        i = n - 1;
        while (i and dif[i] == dif[n - 1]) --i;

        ++i;
        //if (n==1) printf("%d\n", 1);
        //else 
        printf("%d\n", i);
    }
    return 0;
}