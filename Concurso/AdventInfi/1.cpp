#include<bits/stdc++.h>
using namespace std;
#define tam 5
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int x[tam], y[tam];
int main()
{        
    //------------1------------   
    int xx, yy, i = 0, cont = 0;
    cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];    
    while(cin>>xx>>yy)
    {
        x[i%3] += xx;
        y[i%3] += yy;
        i = (i+1)%3;
        if (x[0] == x[1] and x[0] == x[2] and y[0] == y[1] and y[0] == y[2] )
            ++cont;
    }
    cout<<cont<<"\n";
    return 0;
}
