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
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <array>
#include <bitset>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define all( a ) a.begin(), a.end()
#define rall( a ) a.rbegin(), a.rend()
#define fr freopen
#define eb emplace_back
#define ep emplace

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

template < class T > inline void is( T& x )
{
    register char c = getchar();
    for( ; c < '0'; c = getchar() );
    x = 0;
    for( ; c >= '0'; c = getchar() )
        x = x * 10 + c - 48;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

const int N = 2e5+1;

int n,q;
int res;
int depth[N];
int pa[N][19];
int f[N];
vector < int > ke[N];

void enter()
{
    is( n );
    int u,v;
    foru( i, 2, n )
    {
        is( u ), is( v );
        ke[u].eb( v ), ke[v].eb( u );
    }
    is( q );
}

void dfs( int u )
{
    for( int j = 1; pa[u][j-1]; j++ )
        pa[u][j] = pa[pa[u][j-1]][j-1];
    for( int& v : ke[u] )
        if ( !depth[v] )
        {
            depth[v] = depth[u] + 1;
            pa[v][0] = u;
            dfs( v );
        }
}

int log2( int x )
{
    return 31 - __builtin_clz( x );
}

int lca( int u, int v )
{
    if ( depth[u] > depth[v] )
        swap( u, v );
    int k = depth[v] - depth[u];
    while ( k )
    {
        v = pa[v][log2( k & -k )];
        k &= k-1;
    }
    if ( u == v )
        return u;
    for( k = log2( depth[u] ) + 1; k >= 0; k-- )
        if ( pa[u][k] != pa[v][k] )
        {
            u = pa[u][k];
            v = pa[v][k];
        }
    return pa[u][0];
}

void dp( int u, int pa )
{
    for( int& v : ke[u] )
        if ( v != pa )
            dp( v, u ), f[u] += f[v];
    if ( !f[u] )
        res++;
}

void solve()
{
    dfs( depth[1] = 1 );
    int u,v;
    while ( q-- )
    {
        is( u ), is( v );
        if ( depth[u] > depth[v] )
            swap( u, v );
        int x = lca( u, v );
        f[v]++;
        if ( x == u )
            f[u]--;
        else
            f[u]++, f[x] -= 2;
    }
    dp( 1, 0 );
    cout << --res;
}

int main()
{
    #define haid "."

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    enter();
    solve();
}
