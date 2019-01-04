#include <bits/stdc++.h>
using namespace std;

Matrix matMul(Matrix a, Matrix b) 
{
    Matrix c; int i, j, k;
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    for (c.mat[i][j] = k = 0; k < 2; k++)
        c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j])%m;
    return c; 
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>n>>m
        m = pow(10, m);
        cout<<m<<endl;
    }
    return 0;
}