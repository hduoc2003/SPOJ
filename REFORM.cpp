#include <iostream>
#include <fstream>
#include <vector>

#define foru( i, a, b ) for( ll i=a; i<=b; i++ )
#define fr freopen
#define ps push_back
#define haid "1."

using namespace std;

typedef unsigned long long ll;

ll n,m;
ll bridge;
ll res;
vector < ll > low,num,pa,child;
vector < vector < ll > > ke;

void enter()
{
    cin>>n>>m;
    low.resize( n+1 ), num.resize( n+1 );
    pa.resize( n+1 ), ke.resize( n+1 );
    child.resize( n+1 );
    int u,v;
    foru( i, 1, m )
    {
        cin>>u>>v;
        ke[u].ps( v ), ke[v].ps( u );
    }
}

void count_child( ll u )
{
    child[u] = 1;
    for( ll v : ke[u] )
        if ( !child[v] )
            count_child( v ), child[u] += child[v];
}

void dfs( ll u )
{
    low[u] = num[u] = ++low[0];
    for( ll v : ke[u] )
        if ( low[v] )
            low[u] = pa[u] == v ? low[u] : min( low[u], num[v] );
        else
        {
            pa[v] = u, dfs( v );
            low[u] = min( low[u], low[v] );
            if ( low[v] >= num[v] )
            {
                bridge++;
                res += ( ll ) child[v]*( n-child[v] ) - 1;
            }
        }
}

void solve()
{
    count_child( 1 );
    pa[1] = -1, dfs( 1ll );
    if ( child[1] == n )
        cout<<( ll ) res + ( ll ) ( m-bridge )*( n*(n-1)/2-m );
    else
    {
        foru( u, 2, n )
            if ( !low[u] )
            {
                count_child( u );
                pa[u] = -1, dfs( u );
                break;
            }
        if ( low[0] == n )
            cout<<( ll ) child[1]*( n-child[1] )*( m-bridge );
        else
            cout<<0;
    }
}

int main()
{
    ios_base :: sync_with_stdio( false );
    fr( haid"INP", "r", stdin );
    enter();
    solve();
}
