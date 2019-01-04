#include <bits/stdc++.h>

using namespace std;

int f;
int mem[1005][1005];

int dp(int idx, int last, string&s){
	if(idx == s.size() ) return 0;
	if(mem[idx][last] != -1) return mem[idx][last];
	if(!last){
		return  mem[idx][last] = max(dp(idx+1, idx+1, s)+1, dp(idx+1, last, s));
	}
	if((s[last-1]+f-'a')%26 <= s[idx]-'a'){
		return  mem[idx][last] = max(dp(idx+1, idx+1, s)+1, dp(idx+1, last, s));
	}

	return  mem[idx][last] = dp(idx+1, last, s);
}
int main(){

	int  t;
	string s;
	cin >> t;

	while(t--){
		memset(mem, -1, sizeof mem);
		cin >> s >> f;

		cout << dp(0,0, s) << '\n';

		
	}

	
	return 0;
}