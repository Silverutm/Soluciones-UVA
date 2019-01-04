#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
bool matriz[15][15];
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int n;
bool revisar()
{
	bool b=true;
	for (int i = 0; i < n-1 and b; ++i)	
		b = matriz[arr[i]][arr[i+1]];
	return b;
}

int main()
{
	
	char c;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin>>c;
			if (c=='W')
				matriz[i][j]=true;
		}
	do
	{
		if ( revisar() )
		{
			printf("%d", arr[0]);
			for (int i = 1; i < n; ++i)
				printf(" %d", arr[i]);
			break;
		}
	}while (next_permutation(arr, arr +n));
	return 0;
}