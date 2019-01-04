#include <bits/stdc++.h>
using namespace std;

int arr[300];
int differentTeams(string skills)
{
    for (char c:skills)
        ++arr[c];
    return min(arr['b'], min( arr['m'], min( arr['z'], min( arr['p'], arr['c'] ) )));
}

int main()
{
    string s;
    getline(cin, s);
    //cout<<s<<endl;
    cout<<differentTeams(s)<<"\n";
    return 0;
}
