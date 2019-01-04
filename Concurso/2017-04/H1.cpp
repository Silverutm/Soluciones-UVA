#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;
int main()
{
	ll arr[70]; arr[0] = 1;

	for (int i = 1; i < 61; ++i)
		arr[i] = arr[i-1]<<1;

	int ind; ll res, n;
	while(cin>>n and n)
	{
		ind = upper_bound(arr, arr + 61, n) - arr;
		res = n - arr[ind-1] + 1;
		cout<< 2*res - 1<<"\n";
	}
	return 0;
}