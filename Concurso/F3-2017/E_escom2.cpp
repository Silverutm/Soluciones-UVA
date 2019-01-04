#include <bits/stdc++.h>
#define ull unsigned long long
const int MAXC = 2000005;

typedef long long int lli;
using namespace std;
string s;

ull HB[MAXC], B = 71;

ull Subs(const vector<ull>& hasH, int a, int b){
	return hasH[b] - hasH[a-1]*HB[b-a+1];
}

void CB(){
	HB[0] = 1; HB[1] = B;

	for(int i = 2; i <MAXC; i++){
		HB[i] = HB[i-1]*B;
	}
}

ull F(char c){
	return c - 'a' + 1;
}
vector<ull> MhasH(string &s){
	vector<ull> hasH(s.size()+1, 0);
	for(int i = 1; i <= s.size(); i++){
		hasH[i] = hasH[i-1]*B + F(s[i-1]);
		//cout << hasH[i] << '\n';
	}

	return hasH;
}

bool binary(vector<ull>&A, vector<ull> &v, int in, int fin){
	if(in <= 0 || fin >= v.size() || in>fin) return true;
	
	int mid = (in+fin)/2;
	
	if(mid == (v.size()-1)){
		if(Subs(A, 1, mid-1) == Subs(v, 1, mid-1)) return true;
		return false;
	}else if(mid == 1){
		if(Subs(A, mid+1, v.size() - 1) == Subs(v, mid+1, v.size() - 1)) return true;
		return false;
	}
	ull left = Subs(A, 1, mid-1), right =  Subs(A, mid+1, v.size() - 1);
	ull left1 =  Subs(v, 1, mid-1),right1 = Subs(v, mid+1, v.size() - 1);
	if(left == left1 && right == right1) return true;

    if(left != left1 && right != right1) return false;

	if(left != left1 ) return binary(A, v, in, mid-1);
	return binary(A, v, mid+1, fin);

}
lli Solve(vector<ull>& A, vector<ull>&v){
	if(Subs(A,1, A.size() - 1) == Subs(v, 1, v.size() - 1)){

		return A.size()-1;
	}

	else return (lli)binary(A, v, 1, v.size() - 1);
	
}

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);

	int T, N, L;

	CB();
	
	while(cin >> N >> T >> L){

		vector<vector<ull> > v(N);

		for(int i = 0; i < N; i++){
			cin >> s;
			v[i] = MhasH(s);
			//cout<< Subs(v[i], 1, v[i].size() - 1)<< '\n';
		}

		for(int i = 0; i < T; i++){
			cin >> s;
			vector<ull> A = MhasH(s);
			lli cont = 0;
			for(int j =0 ; j < N; j++)
				cont +=	Solve(A,v[j]);

			cout << cont << '\n';
		}
	}
	return 0;
}

