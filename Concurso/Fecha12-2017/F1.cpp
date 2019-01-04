#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector <ii> vii;
typedef vector <ll> vi;

#define tam 55

int n, s, t;
vii Lista[tam];



vi dist1, dist2, predecesor;
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
    predecesor[v.first] = u;
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

        for (int j = 0; j<=n; ++j) Lista[j].clear();
        getline (cin, cad);

        
        for (int j=0; j<n; ++j)
        {
            getline (cin, cad);
            stringstream ss(cad);
            ss>>u;
            //cout<<u<<"  ...\n";
            while (ss>>v>>c)
            {
                //cout<<v<<"  "<<c<<endl;
                Lista[u].push_back(ii{v,c});
            }
        }

        for (int j=0; j<esp; j++ )
        {
            
            cin>>u>>v;
            //cout<<u<<"  "<<v<<"                 000000"<<endl;
            Lista[u].push_back(ii{v,0});
            Lista[v].push_back(ii{u,0});
        }
        cin>>s>>t;
        int tt = t;
        //return 0;
        vi dist3(n,1000000000000000LL );
        predecesor=dist1 = dist3;
        distra1();        
        /*for (int j=0; j<n; ++j)
            cout<<dist1[j]<<"  ";
        cout<<"---------\n";*/
        
        vi respuesta;
        while (predecesor[t] != 1000000000000000LL)
        {
            respuesta.push_back(t);
            t = predecesor[t];
        }
        respuesta.push_back(t);
        reverse(respuesta.begin(), respuesta.end());
        
        if (dist1[tt] < 1000000000000000LL)
        {
            cout<<"Case #"<<i<<": "<<dist1[tt]<<"\n";
            for (int j=0; j<respuesta.size()-1;++j)
                cout<<respuesta[j]<<" ";
            cout<<respuesta[respuesta.size()-1]<<"\n";
        }
        else
        {
            cout<<"Case #"<<i<<": "<<"Path does not exist"<<"\n";    
        }
        


    }

    return 0;

}