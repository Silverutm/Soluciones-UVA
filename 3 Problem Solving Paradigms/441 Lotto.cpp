#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int k, arr[30], i, i1, i2, i3,i4,i5, i6, c=0;
	while (cin>>k and k)
	{
		if (c) cout<<endl;
		++c;

		for (i=0; i<k; ++i)
			cin>>arr[i];

		sort (arr, arr+k);
		for (i1=0; i1<k; ++i1)
			for (i2=i1+1; i2<k; ++i2)
				for (i3=i2+1; i3<k; ++i3)
					for (i4=i3+1; i4<k; ++i4)
						for (i5=i4+1; i5<k; ++i5)
							for (i6=i5+1; i6<k; ++i6)
								cout<<arr[i1]<<" "<<arr[i2]<<" "<<arr[i3]<<" "<<arr[i4]<<" "<<arr[i5]<<" "<<arr[i6]<<"\n";

	}
	return 0;
}