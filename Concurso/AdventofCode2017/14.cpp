#include<bits/stdc++.h>
using namespace std;
#define tam 1505
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//------------2------------
int matriz[135][135];
void busca(int i, int j)
{
    if (matriz[i][j] == 0) return;
    matriz[i][j] = 0;
    busca(i+1,j);
    busca(i-1,j);
    busca(i,j+1);
    busca(i,j-1);
}
int main()
{    
    
        

    //------------1.0------------
    /*int num;
    string s, pup, s2;
    getline(cin, pup);
    for (int kk = 0; kk<128; ++kk)
    {
        int largo, i, salto = 0, j;
        vi v, h;
        for (i=0; i<256; ++i) v.pb(i);
        i = 0;
        
        s = pup;
        stringstream cras; cras<<kk;
        cras>>s2;
        s.pb('-'); s = s + s2;
        //cout<<s<<endl;
        s.pb(17); s.pb(31); s.pb(73); s.pb(47); s.pb(23);
        for (int w = 0; w<64; ++w)
        for (char largo:s)    
        {
            h.clear();
            for (j = 0; j< largo; ++j)
                h.pb( v[(i+j)%v.size()] );
            reverse(h.begin(), h.end());
            for (j = 0; j< largo; ++j)
                v[(i+j)%v.size()] = h[j];
            
            i = (i + largo + salto)%v.size();        
            ++salto;        
        }

        h.clear();
        for (int w = 0; w<16; ++w)
        {
            num = v[16 * w];
            for (int z = 1; z<16; ++z)
                num ^= v[16*w + z];
            h.pb(num);
        }
        for (int e:h)
        {
            int seg = e%16; e /= 16;
            int pri = e%16;
            if (pri>9) printf("%c", pri - 10 + 'a');
            else cout<<pri;
            if (seg>9) printf("%c", seg - 10 + 'a');
            else cout<<seg;
        }
        cout<<endl;
    }*/


    //------------1.1------------
    /*string s;
    int res = 0;
    while(getline(cin, s))
    {
        for (char c:s)
        {
            int qwe = 0;
            if (c>='a' and c<='z')
                qwe = c - 'a' + 10;
            else qwe = c - '0';
            for (int i =0; i<4; ++i)
                res += qwe&(1<<i) ? 1:0;
        }
    }
    cout<<res<<endl;*/


    //------------2------------
    string s;
    int res = 0;
    
    //memset(matriz, 0, sizeof matriz);
    int ii=1, jj=1;
    while(getline(cin, s))
    {
        jj = 1;
        for (char c:s)
        {
            int qwe = 0;
            if (c>='a' and c<='z')
                qwe = c - 'a' + 10;
            else qwe = c - '0';
            
            for (int i =0; i<4; ++i)
            {
                matriz[ii][jj]= qwe&(1<<(4 - 1 -i)) ? 1:0;
                if (matriz[ii][jj]) 
                    ++res;                
                ++jj;
                
            }
            
            
        }        
        ++ii;
    }
    
    res = 0;
    for (ii=1; ii<=128; ++ii)    
        for (jj=1; jj<=128; ++jj)        
            if (matriz[ii][jj])
            {
                busca(ii, jj);
                ++res;
            }                            
    cout<<res<<endl;
    return 0;
}
