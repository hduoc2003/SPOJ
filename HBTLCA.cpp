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

inline void read( int& x )
{
    char c = getchar();
    for( ; c < '0'; c = getchar() );
    x = 0;
    for( ; c >= '0'; c = getchar() )
        x = x * 10 + c - 48;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

const int N = 1e5+1;

int n,q;
vector < int > ke[N];
int pa[N];
int depth[N];
int head[N],f[N];

void enter()
{
    read( n );
    if ( !n )
        exit( 0 );
    int u,v;
    foru( i, 2, n )
    {
        read( u ), read( v );
        ke[u].eb( v ), ke[v].eb( u );
    }
    read( q );
}

void dfs( int u )
{
    f[u] = 1;
    int *it = &ke[u][0];
    for( int& v : ke[u] )
        if ( !f[v] )
        {
            dfs( v );
            f[u] += f[v];
            if ( f[v] > f[*it] )
                it = &v;
        }
    swap( ke[u][0], *it );
}

void hld( int u )
{
    for( int& v : ke[u] )
        if ( !pa[v] )
        {
            depth[v] = depth[u] + 1;
            pa[v] = u;
            head[v] = f[v] * 2 >= f[u] ? head[u] : v;
            hld( v );
        }
}

int lca( int u, int v )
{
    for( ; head[u] != head[v]; v = pa[head[v]] )
        if ( depth[head[u]] > depth[head[v]] )
            swap( u, v );
    return depth[v] < depth[u] ? v : u;
}

inline void print( int u )
{
    if ( u > 9 )
        print( u / 10 );
    putchar( u % 10 + 48 );
}

void solve()
{
    char t;
    int u,v,r = 1;
    dfs( pa[1] = 1 );
    hld( head[1] = 1 );
    while ( q-- )
    {
        for( t = getchar(); t != '?' && t != '!'; t = getchar() );
        read( u );
        if ( t == '!' )
            r = u;
        else
        {
            read( v );
            int uv = lca( u, v );
            if ( lca( uv, r ) != uv )
            {
                print( uv ), putchar( '\n' );
                continue;
            }
            int vr = lca( r, v ), ur = lca( r, u );
            print( depth[vr] > depth[ur] ? vr : ur );
            putchar( '\n' );
        }
    }
}

void reset()
{
    foru( i, 1, n )
    {
        pa[i] = f[i] = 0;
        ke[i].resize( 0 );
    }
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );
    ///fr( "2.out", "w", stdout );
    #endif
    while ( 1 )
    {
        enter();
        solve();
        reset();
    }
}
