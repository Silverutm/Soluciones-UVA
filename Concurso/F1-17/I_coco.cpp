#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> coord ;
int main(int argc, char *argv[]) {
   int N, W, H, R ;
   cin >> N >> R >> W >> H ;
   vector<coord> points;
   for (int i=0; i<N; i++) {
      ll x, y ;
      cin >> x >> y ;
      points.push_back(make_pair(x*R+y, y-x*R)) ;
   }
   sort(points.begin(), points.end()) ;
   vector<ll> ans ;
   for (int i=0; i<points.size(); i++) {
      ll y = points[i].second ;
      vector<ll>::iterator ind = upper_bound(ans.begin(), ans.end(), y) ;
      if (ind == ans.end())
         ans.push_back(y) ;
      else
         *ind = y ;
   }
   cout << ans.size() << endl ;
}



#define MAX_N 10     //tamanho de la matriz

struct Matrix { double mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b, int n) 
{
   Matrix c; 
   int i, j, k;
   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
   for (c.mat[i][j] = k = 0; k < n; k++)
      c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
   return c; 
}

int main()
{
   Matrix original, res;
   //llenar matriz original
   res = original
   for (int i=0; i<num_estados; ++i)
      res = matMul(original, res);
}