#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main()
{
    vector<int>m_pers;
    int pers,edif;
    int arre1[1000],arre2[1000];
    vii mi_vect;
    cin>>pers>>edif;
    while(pers--)
    {
        int a;
        cin>>a;
        m_pers.push_back(a);
    }
    sort(m_pers.begin(),m_pers.end());
    for(int i=0;i<edif;i++)
    {
        int a;
        cin>>a;
        arre1[i]=a;
    }
    for(int i=0;i<edif;i++)
    {
        int a;
        cin>>a;
        arre2[i]=a;
        //mi_vect.push_back(arre1[i],arre2[i]);
    }
    sort(mi_vect.begin(),mi_vect.end());


}