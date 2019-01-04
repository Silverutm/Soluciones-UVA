#include <bits/stdc++.h>
using namespace std;
int a, b, n, m;
struct Matrix { int mat[2][2]; };
Matrix base, identidad;

Matrix matMul(Matrix a, Matrix b) 
{
    Matrix c; int i, j, k;
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    for (c.mat[i][j] = k = 0; k < 2; k++)
        c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j])%m;
    return c; 
}

Matrix fastpow(int n)
{
    auto res = identidad;
    auto x = base;
    while (n)
    {
        if (n&1) res = matMul(res, x);
        x = matMul(x, x);
        n >>= 1;
    }
    return res;
}

int main()
{    
    base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1; base.mat[1][1] = 0;
    identidad.mat[0][0] = identidad.mat[1][1] = 1; identidad.mat[1][0] = 1; identidad.mat[0][1] = 0;
    
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>n>>m;
        m = pow(10, m);
        if (n>=2)
        {
            auto res = fastpow( n - 1 );
            cout<<(res.mat[0][0]*b + res.mat[0][1]*a)%m<<"\n";
        }
        else if  (n==1) cout<<b%m<<"\n";
        else cout<<a%m<<"\n";
    }
    return 0;
}