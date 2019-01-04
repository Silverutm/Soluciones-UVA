#include <bits/stdc++.h>
#define f first
#define s second
#define tam 200005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n, a[tam], b[tam], ans[tam], maxi[tam], w[tam];
ii a_b[tam];
int k;

bool fu(ii u, ii v)		//sort by b_i ascending
{	return u.s < v.s; }

int main()
{	
	int i, j;
	scanf("%lld %d", &n, &k);
	for (i = 1; i <= k; ++i)	//read the intervals
		scanf("%lld %lld", &a_b[i].f, &a_b[i].s);

	sort(a_b + 1, a_b + k + 1, fu);	//sort the intervals
	for (i = 1; i <= k; ++i)
	{								//separate
		a[i] = a_b[i].f;			//to use binary search
		b[i] = a_b[i].s;
		w[i] = b[i] - a[i] + 1;		//calculate w(i)
	}

	for (i = 1; i <= k; ++i)
	{	
		//max{f(j) | b_j < a_i}
		j = (lower_bound(b, b + i, a[i]) - b) - 1;
		ans[i] = w[i] + maxi[j];	//f(j)
		maxi[i] = max(maxi[i-1], ans[i]);	//best solution 'til now
	}
	printf("%lld\n", n - maxi[k]);
	return 0;
}

for (i1 = 0; i1 <3; ++i)
for (i2 = 0; i2 <3; ++i2)
...

for (i13 = 0; i13 <3; ++i13)
	product = category_1[i1] * category_2[i2] * ... * category_13[i13]


function merge(array1, array2)
{
	int i = 0, j = 0;
	array3; //answer
	while ( i<array1.size() and j<array2.size() ){
		
		if (array1[i] == -1 ) //ignore -1
		{	++i; continue; }
		if (array2[j] == -1 ) //ignore -1
		{	++j; continue; }

		if ( array1[i] < array2[j] ) {
			array3.push( array1[i] );
			++i;
		}
		else {
			array3.push( array2[j] );
			++j;	
		}
	}

	//if some array has elements still
	while (i < array1.size() )
		array3.push(array1[i]);
	while (j < array2.size() )
		array3.push(array1[j]);

	return array3
}