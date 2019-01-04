#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int n, color;
vi Lista[30];
int componentes[30];

void buscar(int u)
{
    componentes[u] = color;
    for (auto v:Lista[u] )
        if (componentes[v]==0)
            buscar(v);
}

int main()
{
    int a, b;
    char v;
    string s;
    while (cin>>v)
    {
        getline(cin,s);
        for (int i=0; i<30; ++i)
        {
            Lista[i].clear();
            componentes[i] = 0;
        }
        color = 0;
        n = v - 'A' + 1;
        while (getline(cin,s) and s!="")
        {
            a = s[0] - 'A'; b = s[1] - 'A';
            Lista[a].push_back(b);
            Lista[b].push_back(a);
        }

        for (int i=0; i< n; ++i)
        {
            if (componentes[i] == 0)
            {
                ++color;
                buscar(i);
            }
        }
        printf("%d\n", color);
    }
}