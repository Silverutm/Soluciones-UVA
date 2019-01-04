#include <bits/stdc++.h>
using namespace std;

string s1 = "";
int LIS_C[55];

int LIS(int i)
{
    if (i == 0) return LIS_C[i] = 1;
    if (LIS_C[i] != -1)
        return LIS_C[i];
    for (int j = 0; j < i; j++)
        if (s1[j] < s1[i])
            LIS_C[i] = max(LIS(j) +  1, LIS_C[i]);
    return LIS_C[i];
}
int main(int argc, char const *argv[])
{    
    cin >> s1;
    s1 = (char)('a' - 1) + s1;
    memset(LIS_C, -1, sizeof LIS_C);
    //cout<<"tam "<<s1.size()<<endl;
    for (int i = 0; i < s1.size(); ++i)
        LIS(i);
    cout << 26 - *max_element(LIS_C, LIS_C + s1.size()) + 1 << endl;
    return 0;
}