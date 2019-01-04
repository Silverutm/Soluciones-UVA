#include <iostream>
using namespace std;
int main()
{
    int i;
    string s;
    cin>>s;
    for (char &c:s)
        if (c=='R') c=1;
        else if (c=='B') c=2;
        else c=4;
    char a[10];a[1]='S';a[2]='K'; a[4]='H';
    for (i=2; i<s.size();++i)
        if (s[i-2] + s[i-1] + s[i] == 7)
        {
            cout<<"C";
            i += 2;
        }
        else cout<<a[s[i-2]];
    while (i-2<s.size()) {cout<<a[s[i-2]];++i;}
    cout<<endl;
    return 0;
}