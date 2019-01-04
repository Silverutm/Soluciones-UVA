#include <bits/stdc++.h>
using namespace std;
#define tam 55
char mat[tam][tam];

int main()
{
    int r, c, i, j, x, y;
    memset(mat, '.', sizeof mat);
    cin>>r>>c;
    for ( i=1; i<=r; ++i)
        for ( j=1; j<=c; ++j)
            cin>>mat[i][j];

    x = y = tam;
    for ( i=1; i<=r; ++i)
        for ( j=1; j<=c; ++j)
            if (mat[i][j]== '*')
            {
                x = j; y = i;
                j = i = tam;
            }
    if (x == tam) 
    {
        cout<<"NO\n";
        return 0;
    }

    int largo = 0;
    while (mat[y][x + largo] == '*') ++largo;

    int cuadrado = 0;
    for ( i=0; i<largo; ++i)
        for ( j=0; j<largo; ++j)
            cuadrado += mat[y +i][x+j] == '*';
    if (cuadrado != largo*largo)
    {
        cout<<"NO\n";
        return 0;
    }

    int total = 0;
    for ( i=1; i<=r; ++i)
        for ( j=1; j<=c; ++j)
            total += mat[i][j] == '*';

    if (total != cuadrado)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}

10 3
8 8

10 1
9 3
8 8
5 9