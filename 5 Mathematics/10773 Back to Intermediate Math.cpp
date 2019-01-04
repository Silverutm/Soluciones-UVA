#include <iostream>
#include <cmath>
using namespace std;

int main()
{    
    double d,v,u,t1,t2;
    int t;
    
    cin>>t;
    for(int caso=1; caso<=t ; ++caso)
    {
        cin>>d>>v>>u;
        
        if( v>=u or u==0 or v==0 )
        {
            printf("Case %d: can't determine\n", caso);
            continue;
        }
        
        t1=d/u;
        t2=d/sqrt(u*u-v*v);
        
        printf("Case %d: %.3lf\n",caso, fabs(t2-t1) );
    }
    return 0;
}