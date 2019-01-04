#include <bits/stdc++.h>
using namespace std;

string arr[] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#","LA", "LA#", "SI"};

int main()
{
    int n;
    string s;
    cin>>n>>s;
    int i=0;
    while(arr[i]!=s)  ++i;
    cout<<arr[(i+12-n)%12]<<endl;
    return 0;
}