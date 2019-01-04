#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	freopen("lazy_loading.txt","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	int n, w;
	vector<int> v;
	cin>>T;
	for(int k = 1; k <= T; k++) {
		int sol = 0;
		cin>>n;
		v.clear();
		for(int i = 0; i < n; i++) {
			cin>>w;
			v.push_back(w);
		}
		sort(v.begin(),v.end());
		int a = 0, b = v.size() - 1;
		while (v.size() > 0 and v[b] >= 50) {
			sol++;
			b--;
			v.pop_back();
		}
		while (a < b) {
			a += 50/v[b] + (50 % v[b] == 0 ? 0 : 1) - 1;
			if (a <= b) {
				sol++;
				b--;
			}
		}
		cout<<"Case #"<<k<<": "<<sol<<endl;

	}
	return 0;
}