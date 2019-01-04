#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef long long ll;
#define pb push_back

#define tam 25

int arr[tam];

//vector <int> lista[328389]

int main()
{
    int n, i, k;
    scanf("%d", &n);
    for (i=0; i<n; ++i)
    {
        scanf("%d", &k);
        ++arr[k];
    }

    double res = 2.0*arr[0];
    res += arr[1];
    res += arr[2]/2.0;
    res += arr[4]/4.0;
    res += arr[8]/8.0;
    res += arr[16]/16.0;
    printf("%lf\n", res);

    
    return 0;
}