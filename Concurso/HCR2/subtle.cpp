#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int  t;
	int i = 0;
	cin >> t;
	while(t--)
	{
		cout << "Case #" << ++i << ": ";
		long long m, n, k;
		cin >> n >> m >> k;
		long long bloques_vertical = 90000000 ;
		long long bloques_horizontal = 90000000 ;
		long long bloques_diagonal1 = 90000000 ;
		long long bloques_diagonal2 = 90000000 ;

		if (3 + 2 * k <= m && k + 1 <= n)
			n % k == 0 ? bloques_vertical = n / k : bloques_vertical = n / k  + 1;

		if (5 * k <= m && 4 * k + 1 <= n)
			bloques_diagonal1 = 5;

		swap(n,m);
 		if (3 + 2 * k <= m && k + 1 <= n)
			n % k == 0 ? bloques_horizontal = n / k : bloques_horizontal = n / k  + 1;
		if (5 * k <= m && 4 * k + 1 <= n)
			bloques_diagonal2 = 5;

		long long ans =  min(bloques_vertical, min(bloques_horizontal, min(bloques_diagonal1, bloques_diagonal2)));

		if (ans != 90000000)
			cout << ans << endl;
		else
			cout << "-1" << endl;

	}
	return 0;
}