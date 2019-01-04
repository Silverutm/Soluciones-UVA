#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector <ii> vii;
typedef vector <ll> vi;

#define tam 50005





int n, m, s, f, t;
vii Lista[tam];
vii vuelos;


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


void distra2()
{
    /*vi dist2(n,1000000000000000LL );*/ dist2[t] = 0;
    
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, t));
    while (!pq.empty()) {
    // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist2[u]) continue;
    // this is a very important check
    for (int j = 0; j < (int)Lista[u].size(); j++) {
    ii v = Lista[u][j];
    // all outgoing edges from u
    if (dist2[u] + v.second < dist2[v.first]) {
    dist2[v.first] = dist2[u] + v.second;
    // relax operation
    pq.push(ii(dist2[v.first], v.first));
    } } }
}


int main()
{  
    
    
    ll u, v, c;
    cin>>n>>m>>f>>s>>t;
    vi dist3(n,1000000000000000LL );
    dist1 = dist2 = dist3;
    while(m--)
    {
        cin>>u>>v>>c;
        Lista[u].push_back(ii{v,c});
        Lista[v].push_back(ii{u,c});
    }
    distra1(); distra2();
    ll res = dist1[t];
    while(f--)
    {
        //vuelos.push_back(ii{u, v});
        cin>>u>>v;
        res = min(res, dist1[u] + dist2[v]);
    }
    cout<<res<<endl;


}