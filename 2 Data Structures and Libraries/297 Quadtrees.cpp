#include <bits/stdc++.h>
using namespace std;
#define tam 6000
int a1[tam], a2[tam];
string s1, s2;
int i;
void busca(int prof,int p, string &s, int arr[])
{
    if (i>=s.size()) return;
    
    if (s[i] == 'p')
    {
        ++i;
        busca(prof + 1, 4*p-2, s, arr);
        ++i;
        busca(prof + 1, 4*p-1, s, arr);
        ++i;
        busca(prof + 1, 4*p, s, arr);
        ++i;
        busca(prof + 1, 4*p+1, s, arr);
        arr[p] = arr[4*p-2] + arr[4*p-1] + arr[4*p] + arr[4*p+1];
    }
    else if (s[i] == 'e')
        arr[p] = 0;
    else //f
        arr[p] = 1024/ (1<<(2 * prof ) );
}
//int j;
int recorrido(int p, int prof)
{
    if ( a1[p] == 1024/ (1<<(2 * prof ) ) or a2[p] == 1024/ (1<<(2 * prof ) ))
        return max(a1[p], a2[p]);
    if (a1[p] == 0 and a2[p] == 0) 
        return 0;
    return recorrido( 4*p - 2, prof + 1) + recorrido( 4*p - 1, prof + 1)
        + recorrido( 4*p, prof + 1) + recorrido( 4*p + 1, prof + 1);
}

int main()
{
    int n;
    
    cin>>n;
    while(n--)
    {
        cin>>s1>>s2;
        memset(a1, 0, sizeof a1);
        memset(a2, 0, sizeof a2);
        i = 0;
        busca(0, 1, s1, a1);
        i = 0;
        busca(0, 1, s2, a2);        

        cout<<"There are "<<recorrido(1, 0)<<" black pixels.\n";
    }
    return 0;
}