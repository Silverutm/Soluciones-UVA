#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

typedef complex< lf >       pt;

const int MAXN = int( 50 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const int dx[ ] = { 0, 1, 0, -1 };
const int dy[ ] = { 1, 0, -1, 0 };

const int max_n1 = 2000;
const int max_n2 = 2000;
const int max_m  = 7000;

struct Hopcroft_Karp {

  int n1, n2, edges;
  vi last, prev, head, matching, dist, q;
  vb used, vis;

  Hopcroft_Karp( ) :
    last( max_n1 ), prev( max_m ), head( max_m ),
    matching( max_n2 ), dist( max_n1 ), q( max_n1 ),
    used( max_n1 ), vis( max_n1 ) {
  }

  void init( int n1, int n2 ) {
    this->n1 = n1;
    this->n2 = n2;
    edges = 0;
    fill( last.begin( ), last.begin( )+n1, -1 );
  }

  void add_edge( int u, int v ) {
    head[ edges ] = v;
    prev[ edges ] = last[ u ];
    last[ u ] = edges++;
  }

  void bfs( ) {
    fill( dist.begin( ), dist.begin( )+n1, -1 );
    int size_q = 0;
    for( int u = 0; u < n1; u++ ) {
      if( !used[ u ] ) {
        q[ size_q++ ] = u;
        dist[ u ] = 0;
      }
    }
    for( int i = 0; i < size_q; i++ ) {
      int u1 = q[ i ];
      for( int e = last[ u1 ]; e >= 0; e = prev[ e ] ) {
        int u2 = matching[ head[ e ] ];
        if( u2 >= 0 && dist[ u2 ] < 0 ) {
          dist[ u2 ] = dist[ u1 ] + 1;
          q[ size_q++ ] = u2;
        }
      }
    }
  }

  bool dfs( int u1 ) {
    vis[ u1 ] = true;
    for( int e = last[ u1 ]; e >= 0; e = prev[ e ] ) {
      int v = head[ e ];
      int u2 = matching[ v ];
      if( u2 < 0 || ( !vis[ u2 ] && dist[ u2 ] == dist[ u1 ]+1 && dfs( u2 ) ) ) {
        matching[ v ] = u1;
        used[ u1 ] = true;
        return true;
      }
    }
    return false;
  }

  int max_matching( ) {
    fill( used.begin( ), used.begin( )+n1, false );
    fill( matching.begin( ), matching.begin( )+n2, -1 );
    int ans = 0;
    while( true ) {
      bfs( );
      fill( vis.begin( ), vis.begin( )+n1, false );
      int f = 0;
      for( int u = 0; u < n1; u++ ) {
        if( !used[ u ] && dfs( u ) ) {
          f++;
        }
      }
      if( f == 0 ) {
        return ans;
      }
      ans += f;
    }
    return 0;
  }

}hk;

int n, m, tc;
string board[ MAXN ];
int id[ MAXN ][ MAXN ], seen[ MAXN ][ MAXN ];

bool is_valid( int x, int y ) {
  return ( 0 <= x && x < n && 0 <= y && y < m );
}

void dfs( int x, int y ) {
  seen[ x ][ y ] = tc;
  if( board[ x ][ y ] == 'C' ) {
    board[ x ][ y ] = 'W';
    return ;
  }
  for( int k = 0; k < 4; k++ ) {
    int nx = x+dx[ k ], ny = y+dy[ k ];
    if( is_valid( nx, ny ) && board[ nx ][ ny ] != 'W' && seen[ nx ][ ny ] != tc )
      dfs( nx, ny );
  }
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  for( tc = 1; cin >> n >> m; tc++ ) {
    for( int i = 0; i < n; i++ )
      cin >> board[ i ];
    int ans = 0;
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < m; j++ ) {
        if( board[ i ][ j ] == 'L' && seen[ i ][ j ] != tc ) {
          dfs( i, j );
          ans++;
        }
      }
    }
    int x = 0;
    for( int i = 0; i < n; i++ )
      for( int j = 0; j < m; j++ )
        if( board[ i ][ j ] == 'C' )
          id[ i ][ j ] = x++;
    hk.init( x, x );
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < m; j++ ) {
        if( board[ i ][ j ] != 'C' ) continue;
        for( int k = 0; k < 4; k++ ) {
          int ni = i+dx[ k ], nj = j+dy[ k ];
          if( is_valid( ni, nj ) && board[ ni ][ nj ] == 'C' )
            hk.add_edge( id[ i ][ j ], id[ ni ][ nj ] );
        }
      }
    }
    ans += ( x-hk.max_matching( )/2 );
    cout << ans << "\n";
  }

  return 0;
}
