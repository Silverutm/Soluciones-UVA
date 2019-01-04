#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector <ii> vii;
typedef vector <ll> vi;

#define tam 55

int n, s, t;
vii Lista[tam];



vi dist1, dist2;
void distra1()
{
    /*vi dist1(n,1000000000000000LL );*/ dist1[s] = 0;
    
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
    while (!pq.empty()) {
    // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist1[u]) continue;
    // this is a very important check
    for (int j = 0; j < (int)Lista[u].size(); j++) {
    ii v = Lista[u][j];
    // all outgoing edges from u
    if (dist1[u] + v.second < dist1[v.first]) {
    dist1[v.first] = dist1[u] + v.second;
    // relax operation
    pq.push(ii(dist1[v.first], v.first));
    } } }
}




int main()
{  
    int casos, x, esp;
    ll u, v, c;
    vi tres;
    string cad;
    cin>>casos;
    for (int i=1; i<=casos; ++i)
    {
        cin>>n>>esp;
        getline (cin, cad);
        bool ya  = true;
        while (ya and getline (cin, cad) )
        {
            tres.clear();
            stringstream ss(cad);
            while (ss>>x) tres.push_back(x);
            //cout<<tres.size()<<"  ..\n";
            if (tres.size() == 3)
            {
                u = tres[0]; v = tres[1]; c= tres[2];
                Lista[u].push_back(ii{v,c});
                //Lista[v].push_back(ii{u,c});
            }
            else
            {
                //cout<<"aqui\n";
                ya = false;
                //cout<<esp<<"  ........"<<endl;
                if (esp==0)
                {
                    s = tres[0]; t = tres[1];
                }
                else
                {
                    //cout<<"alla\n";
                    
                    for (int j=0; j<tres.size(); j +=2)
                    {
                        u = tres[j]; v = tres[j + 1];
                        Lista[u].push_back(ii{v,0});
                        Lista[v].push_back(ii{u,0});
                    }
                    //cout<<"mas alla\n";
                    
                    cin>>s>>t;
                    
                    //cout<<"ahora si\n";
                    
                }
                
                break;
            }
        }
        //return 0;
        vi dist3(n,1000000000000000LL );
        dist1 = dist3;
        distra1();
        cout<<s<<"  "<<t<<"  ";
        cout<<dist1[t]<<endl;


    }

    return 0;

}