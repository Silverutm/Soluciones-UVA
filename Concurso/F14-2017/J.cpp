#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <int> vi;
#define tam 33
#define pb push_back

string mat[tam], mat2[tam];
int h[tam], v[tam];
int main()
{
    int n, i, j;    
    while (scanf("%d", &n)==1)
    {        
        for (i =0; i<n; ++i)
            cin>>mat[i];
        for (j =0; j<n; ++j)
        {
            mat2[j] = "";
            for (i = 0; i<n; ++i)
                mat2[j].pb(mat[i][j]);
            //cout<<mat2[i]<<endl;
        }
        //cout<<endl;

        //map<string, int> mh, mv;
        for (i =0; i<n; ++i)
        {
            sort(mat[i].begin(), mat[i].end());
            sort(mat2[i].begin(), mat2[i].end());
            
            //cout<<mat[i]<<endl;
            //cout<<mat2[i]<<endl<<endl;
        }

        for (i =0; i<n; ++i)
            for (h[i] = v[i] = j = 0; j<n; ++j)
            {
                if (mat[i] == mat[j]) ++h[i];
                if (mat2[i] == mat2[j]) ++v[i];
            }

        int i1, j1;
        i1 = min_element(h, h + n) - h;
        j1 = min_element(v, v + n) - v;

        int i2 = (i1 + 1)%n;
        
        printf("%d %d ", i1 + 1, j1 + 1);
        bool caca = true;
        for ( i = 0; i<n; ++i)
        {            
            
            
            caca = false;
            for ( j = 0; j<n; ++j)
                if (mat[i1][j] == mat[i2][i])
                {
                    caca = true;
                    continue;
                    
                }
            if (not caca)
            {
                printf("%c\n", mat[i2][i]);
                break;
            }
        }


        


        
    }
    return 0;
}