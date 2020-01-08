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

#define foru( i, a, b ) for( int i = a; i <= (b); i++ )
#define ford( i, a, b ) for( int i = a; i >= (b); i-- )
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

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

const int N = 2e4+1, M = 8001 << 1;

int n,m;
int k;
int low[M],num[M];
int sat[M];
vector < int > ke[M],g[M];
stack < int > s;

void add( vector < int > ke[], int u, int v )
{
    u = abs( u ) << 1 | ( u > 0 );
    v = abs( v ) << 1 | ( v > 0 );
    ke[u].eb( v );
}

void enter()
{
    cin >> n >> m;
    int u,v;
    foru( i, 1, n )
    {
        cin >> u >> v;
        add( ke, -u, v ), add( ke, -v, u );
        add( g, u, -v ), add( g, v, -u );
    }
}

void setFalse( int u )
{
    sat[u] = 1;
    for( int& v : g[u] )
        if ( sat[v] != 1 )
            setFalse( v );
}

void dfs( int u )
{
    low[u] = num[u] = ++low[0];
    s.ep( u );
    for( int& v : ke[u] )
        if ( low[v] )
            mini( low[u], num[v] );
        else
            dfs( v ), mini( low[u], low[v] );
    if ( low[u] == num[u] )
    {
        int v;
        do
        {
            v = s.top(), s.pop();
            low[v] = num[v] = N;
            if ( sat[u] != 1 )
            {
                sat[v] = 2;
                setFalse( v ^ 1 );
            }
        }
        while ( u != v );
    }
}

void solve()
{
    m = m << 1 | 1;
    for( int i = 3; i <= m; i += 2 )
        if ( !low[i] )
            dfs( i );
    vector < int > res;
    for( int i = 3; i <= m; i += 2 )
    {
        if ( sat[i] == sat[i^1] )
        {
            cout << "NO";
            return;
        }
        if ( sat[i] == 2 )
            res.eb( i >> 1 );
    }
    cout << "YES\n" << res.size() << '\n';
    for( int& i : res )
        cout << i << " ";
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
