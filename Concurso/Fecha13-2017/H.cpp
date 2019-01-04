#include <bits/stdc++.h>
using namespace std;
#define tam 200005

int arr[tam];
int main()
{
    int n, i, contador;
    while (scanf("%d", &n) == 1)
    {
        for (i = 1; i<=n; ++i)
            scanf("%d", &arr[i]);
        
        contador = 0;
        for (i = 1; i<=n; ++i)
        while (arr[i] != i)
        {
            ++contador;
            swap(arr[i], arr[ arr[i] ]);
        }
        printf("%d\n", contador);
    }
    return 0;
}