#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
long long suma;

vi combinar (vi s1,vi s2){
    vi resp;
    int i=0, j=0;
    while( i<s1.size() and j<s2.size() ){
        if(s1[i]<s2[j]){
            resp.push_back(s1[i]);
            i++;
        }
        else{
            resp.push_back(s2[j]);
            j++;
            suma=suma+(long long)s1.size()-i;
        }
    }
    if( i==s1.size() )
        for(j;j<s2.size();j++)
            resp.push_back(s2[j]);
    else
        for(i;i<s1.size();i++)
            resp.push_back(s1[i]);
    return resp;

}

vi margesort(vi l){
    if(l.size()==1)
        return l;
    vi v1(l.begin(), l.begin()+l.size()/2 );
    vi v2(l.begin()+l.size()/2, l.end() );
    vi l1=margesort(v1);
    vi l2=margesort(v2);
    return combinar(l1,l2);
}

int main(){
    int x, n;
    vi i;
    while(cin>>x && x){
        suma=0;
        for(x;x>0;x--){
            cin>>n;
            i.push_back(n);
        }
        i=margesort(i);
        i.clear();
        cout<<suma<<endl;
    }
    return 0;
}