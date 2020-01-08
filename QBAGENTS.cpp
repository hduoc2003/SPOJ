#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <tuple>
#include <chrono>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <array>
#include <bitset>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a, _b = b; i <= _b; i++ )
#define ford( i, a, b ) for( int i = a; i >= (b); i-- )
#define all( a ) a.begin(), a.end()
#define rall( a ) a.rbegin(), a.rend()
#define fr freopen
#define eb emplace_back
#define ep emplace
#define in read()

using namespace std;

template < class X, class Y >
bool mini( X& a, const Y& b )
{
    if ( a > b ) { a = b; return 1; } return 0;
}

template < class X, class Y >
bool maxi( X& a, const Y& b )
{
    if ( a < b ) { a = b; return 1; } return 0;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

const int N = 251;

struct data
{
    int u,v,k;

    data( ci u, ci v, ci k ): u( u ), v( v ), k( k ) {}
};

int n,m;
int s,f;
vector < int > ke[N];
int d[N][N][2];
bool flag[N][N];

void enter()
{
    cin >> n >> m >> s >> f;
    int u,v;
    while ( m-- )
    {
        cin >> u >> v;
        ke[u].eb( v );
    }
}

void solve()
{
    queue < data > q;
    foru( i, 1, n )
        foru( j, 1, n )
            d[i][j][0] = d[i][j][1] = 1 << 30;
    q.ep( s, f, 0 );
    d[s][f][0] = 0;
    while ( q.size() )
    {
        data t = q.front();
        int u = t.u, v = t.v, k = t.k;
        q.pop();
        for( int& r : ke[k&1 ? u : v] )
        {
            int& F = k & 1 ? d[r][v][0] : d[u][r][1];
            if ( mini( F, d[u][v][k]+1 ) )
                k & 1 ? q.ep( r, v, 0 ) : q.ep( u, r, 1 );
        }
    }
    int res = 1 << 30;
    foru( i, 1, n )
        mini( res, d[i][i][0] );
    cout << ( res == 1 << 30 ? -1 : res >> 1 );
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    enter();
    solve();
}
