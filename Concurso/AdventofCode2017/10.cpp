#include<bits/stdc++.h>
using namespace std;
#define tam 1505
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{    
    int largo, i, salto = 0, j;
    vi v, h;
    for (i=0; i<256; ++i) v.pb(i);
    i = 0;
    
    //------------1------------
    /*while (cin>>largo)
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
    cout<<v[0] * v[1] <<endl;*/

    //------------2------------
    int num;
    string s;
    getline(cin, s);
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
    return 0;
}
