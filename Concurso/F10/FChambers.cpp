#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
vector<int>digit[20];
vector<string>vs;
typedef long long ll;
ll fibo[100];
bool f(const string &s){
	int pos = 0;
	int last = -1;
	//cout << "ENTRA LA PUTA MADRE CONCHA DE LA LORA " <<endl;
	while(true){
		if(s.size() == pos)return true;
		int u = s[pos] - '0';
		int a = -1, b = digit[u].size();
		//cout<< last << " " << u << " " << a << " " << b << endl;
		while(b - a > 1){
			int mid = (a + b) >> 1;
			if(digit[u][mid] >= last)b = mid;
			else a = mid;
		}
	//	cout << u << " " << a << " " << b << endl;
		if(b == digit[u].size())return false;
		last = digit[u][b] + 1;
		pos++;
	}
	return false;
}
string con(ll a,ll b){
	stringstream ss;
	ss << a << b;
	string u,v;
	ss >> u, ss >> v;
	string k = u + v;
	return k;
}
int main(){
	fibo[0] = fibo[1] = 1LL;
	for(int i = 2; i <= 91 ;i++){
		fibo[i] = (fibo[i - 1] + fibo[i - 2]);
		//cout << fibo[i] << "\n";
	}
	for(int i = 0; i <= 91;i++){
		for(int j = 0; j <= 91;j++){
			if(i == j)continue;
			vs.push_back(con(fibo[i],fibo[j]));
		}
	}
	//for(int i = 0; i < 10;i++)cout << vs[i] << endl;
	sort(vs.begin(),vs.end());
	vs.resize(unique(vs.begin(),vs.end()) - vs.begin());
	{
		string s;
		while(cin >> s){
			for(int i = 0; i <= 9;i++)digit[i].clear();
			for(int i = 0; i < s.size();i++){
				if(isdigit(s[i]))
					digit[s[i] - '0'].push_back(i);
			}
			/*for(int i = 0; i <= 9;i++){
				cout << i << " :  \n";
				for(auto u:digit[i])cout << u << " ";
				cout << endl;
			}*/
			int ans  = 0;
			for(int i = 0; i < vs.size();i++){
			//	if(f(vs[i]))cout <<"MY CADENA "<< vs[i] << endl;
				ans += f(vs[i]);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}




