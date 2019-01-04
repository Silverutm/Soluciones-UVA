#include<bits/stdc++.h>
using namespace std;
#define tam 5000000
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{        
    //------------1------------
    ll ant_A = 289, ant_B = 629;
    ll gen_A = 16807, gen_B = 48271;
    ll mod = 2147483647;

    for (int i = 1; i<=tam; ++i)
    {
        do{ant_A = ant_A * gen_A % mod;}while(ant_A%(1<<2));
        do{ant_B = ant_B * gen_B % mod;}while(ant_B%(1<<3));
        if (ant_A%(1<<16) == ant_B%(1<<16))
            cout<<i<<"\n";
        //cout<<ant_A%(1<<16)<<"  "<<ant_B%(1<<16)<<"\n";
    }
    return 0;
}
