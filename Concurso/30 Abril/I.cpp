#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxSize 21

int mat[maxSize][maxSize], mino[maxSize][maxSize], aux[maxSize][maxSize];

void rotate(int H, int W) {
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			aux[j][H - i - 1] = mino[i][j];
		}
	}
	FOR(i, 0, W) {
		FOR(j, 0, H) mino[i][j] = aux[i][j];
	}
}

void mirrorY(int H, int W) {
	FOR(i, 0, H/2) {
		FOR(j, 0, W) {
			swap(mino[H-i-1][j], mino[i][j]);
		}
	}
}

void mirrorX(int H, int W) {
	FOR(i, 0, H) {
		FOR(j, 0, W/2) {
			swap(mino[i][j], mino[i][W - j - 1]);
		}
	}
}

void imprime(int H, int W)
{
	return;
	int i, j;
	for (i=0; i<H; ++i, cout<<endl)
		for (j=0; j<W; ++j)
			cout<<mino[i][j]<<" ";
	cout<<endl;
}

int main() {
	int H, W, F, G;
	while (cin >> W >> H) {
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cin >> mino[i][j];
			}
		}
		cin >> F >> G;
		FOR(i, 0, F) {
			FOR(j, 0, G) {
				cin >> mat[i][j];
			}
		}
		//imprime(W, H);
		//return 0;
		bool pos = false;
		FOR(morekk, 0, 2) {
			//mirrorY(H, W);
			FOR(moreK, 0, 2) {
				imprime(H, W);
				mirrorX(H, W);
				FOR(k, 0, 4) {
					imprime(H, W);
					rotate(H, W);
					swap(H, W);
					int fr = INF, fc = INF, lr=0, lc=0;
					FOR(kk, 0, H) {
						FOR(kkk, 0, W) {
							if (mino[kk][kkk]) fr = min(fr, kk), fc = min(fc, kkk), lc = max(lc, kkk + 1), lr = max(lr, kk + 1);
						}
					}
					FOR(i, 0, F - lr + 1+fr) {
						FOR(j, 0, G - lc + 1+fc) {
							bool v = true;
							FOR(kk, fr, lr) {
								FOR(kkk, fc, lc) {
									if (mat[i + kk - fr][j + kkk - fc] && mino[kk][kkk]) v = false;
								}
							}
							if (v) pos = true;
						}
					}
				}
			}
		}
		if (pos) cout << "YES";
		else cout << "IMPOSSIBLE";
	}
	return 0;
}
