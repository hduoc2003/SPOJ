#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <numeric>
#include <limits.h>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define all( a ) a.begin(), a.end()
#define rall( a ) a.rbegin(), a.rend()
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

const int N = 4e4+1, Q = 1e5+2;
const int block = sqrt( N );

struct query
{
    int l,r,id,lca;
};

int n,qr;
query q[Q];
int w[Q];
vector < int > ke[N];
int in[N],out[N];
int depth[N];
int pa[N][16];
int vtx[N<<1];
int res[Q];

void enter()
{
    is( n ), is( qr );
    foru( i, 1, n )
        is( w[i] );
    int u,v;
    foru( i, 2, n )
    {
        is( u ), is( v );
        ke[u].eb( v ), ke[v].eb( u );
    }
}

void dfs( int u )
{
    in[u] = ++in[0];
    for( int j = 1; pa[u][j-1]; j++ )
        pa[u][j] = pa[pa[u][j-1]][j-1];
    for( int& v : ke[u] )
        if ( !in[v] )
        {
            depth[v] = depth[u] + 1;
            pa[v][0] = u;
            dfs( v );
        }
    out[u] = ++in[0];
}

int log2( int i )
{
    return 31 - __builtin_clz( i );
}

int lca( int u, int v )
{
    if ( depth[u] < depth[v] )
        swap( u, v );
    int k = depth[u] - depth[v];
    while ( k )
    {
        u = pa[u][log2( k & -k )];
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

bool is_child( int u, int v )
{
    return in[u] >= in[v] && out[u] <= out[v];
}

void compress()
{
    vector < int > b( w+1, w+n+1 );
    sort( all( b ) );
    foru( i, 1, n )
        w[i] = lower_bound( all( b ), w[i] ) - b.begin() + 1;
}

void enter_query()
{
    int u,v;
    foru( i, 1, qr )
    {
        is( u ), is( v );
        if ( depth[u] > depth[v] )
            swap( u, v );
        if ( is_child( v, u ) )
            q[i].l = in[u], q[i].r = in[v];
        else
        {
            q[i].lca = lca( u, v );
            if ( out[u] > in[v] )
                swap( u, v );
            q[i].l = out[u], q[i].r = in[v];
        }
        q[i].id = i;
    }
}

void init()
{
    dfs( depth[1] = 1 );
    compress();
    foru( i, 1, n )
        vtx[in[i]] = vtx[out[i]] = i;
    enter_query();
    sort( q+1, q+qr+1, [&]( query& a, query& b ) -> bool
    {
        if ( a.l/block != b.l/block )
            return a.l < b.l;
        return a.l/block & 1 ? a.r < b.r : a.r > b.r;
    });
}

void solve()
{
    init();
    foru( i, 1, n )
        in[i] = out[i] = 0;
    int l = 1, r = 0;
    int cnt = 0;
    auto add_rmv = [&]( int i ) -> void
    {
        int u = vtx[i];
        if ( out[u] )
        {
            if ( !--in[w[u]] )
                cnt--;
        }
        else
            if ( ++in[w[u]] == 1 )
                cnt++;
        out[u] ^= 1;
    };
    foru( i, 1, qr )
    {
        while ( l < q[i].l )
            add_rmv( l++ );
        while ( l > q[i].l )
            add_rmv( --l );
        while ( r < q[i].r )
            add_rmv( ++r );
        while (  r > q[i].r )
            add_rmv( r-- );
        res[q[i].id] = cnt;
        if ( q[i].lca && !in[w[q[i].lca]] )
            res[q[i].id]++;
    }
    foru( i, 1, qr )
        cout << res[i] << "\n";
}

int main()
{
    #define haid "1."

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    enter();
    solve();
}
