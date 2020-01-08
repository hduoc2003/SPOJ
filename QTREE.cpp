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
#include <functional>

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

struct edge
{
    int u,v;
};

const int N = 1e4+1, inf = -1e9;

int test;
int n;
int c[N];
vector < pair < int, int > > ke[N];
int f[N],pa[N],head[N],depth[N];
int rcs[N],pos[N],cs[N];
int t[N<<1];

#define u first
#define id second

void enter()
{
    cin >> n;
    int u,v;
    foru( i, 1, n-1 )
    {
        cin >> u >> v >> c[i];
        ke[u].eb( v, i );
        ke[v].eb( u, i );
    }
}

void modify( int i, int val )
{
    for( t[i += n] = val; i >>= 1; )
        t[i] = max( t[i<<1], t[i<<1|1] );
}

int get( int l, int r )
{
    int res = inf;
    for( l += n, ++r += n; l < r; l >>= 1, r >>= 1 )
    {
        if ( l & 1 )
            maxi( res, t[l++] );
        if ( r & 1 )
            maxi( res, t[--r] );
    }
    return res;
}

void dfs( int u )
{
    f[u] = 1;
    int vmax = -1;
    for( int i = 0, sz = ke[u].size(); i < sz; i++ )
    {
        int v = ke[u][i].u;
        if ( v != pa[u] )
        {
            pa[v] = u, dfs( v );
            f[u] += f[v];
            if ( vmax < 0 || f[v] > f[ke[u][vmax].u] )
                vmax = i;
        }
    }
    if ( vmax > 0 )
        swap( ke[u][vmax], ke[u][0] );
}

void hld( int u )
{
    pos[u] = ++pos[0];
    for( auto& p : ke[u] )
    {
        int v = p.u;
        if ( v != pa[u] )
        {
            pa[v] = u, depth[v] = depth[u] + 1;
            if ( f[v]*2 >= f[u] )
            {
                head[v] = head[u];
                modify( pos[0]+1, c[p.id] );
            }
            else
                head[v] = v;
            rcs[p.id] = pos[0]+1, cs[pos[0]+1] = p.id;
            hld( v );
        }
    }
}

void init()
{
    foru( i, 1, n << 1 )
        t[i] = inf;
    dfs( 1 );
    pos[0] = 0;
    hld( head[1] = 1 );
}

int lca( int u, int v )
{
    for( ; head[u] != head[v]; v = pa[head[v]] )
        if ( depth[head[v]] < depth[head[u]] )
            swap( u, v );
    return depth[u] < depth[v] ? u : v;
}

int query( int u, int v )
{
    if ( u == v )
        return 0;
    int uv = lca( u, v );
    auto lift = [&]( int u ) -> int
    {
        int res = inf;
        while ( depth[u] > depth[uv] )
        {
            maxi( res, get( max( pos[uv], pos[head[u]] )+1, pos[u] ) );
            if ( depth[head[u]] > depth[uv] )
                maxi( res, c[cs[pos[head[u]]]] );
            u = pa[head[u]];
        }
        return res;
    };
    return max( lift( u ), lift( v ) );
}

void solve()
{
    init();
    string type;
    int u,v;
    while ( cin >> type )
    {
        if ( type[0] == 'D' )
            return;
        cin >> u >> v;
        if ( type[0] == 'Q' )
            cout << query( u, v ) << '\n';
        else
            modify( rcs[u], c[u] = v );
    }
}

void reset()
{
    foru( i, 1, n )
        ke[i].clear();
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    cin >> test;
    while ( test-- )
    {
        enter();
        solve();
        reset();
    }
}
