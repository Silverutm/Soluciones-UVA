#include <bits/stdc++.h>
#define tam 513
using namespace std;

int cuad[tam * tam];
int main()
{
    int i, j;
    for ( i=1; i<= tam; ++i)
        cuad[i*i] = i;

    for ( i=1; i<= tam; ++i)
        for ( j=1; j<= i; ++j)
    return 0;
}