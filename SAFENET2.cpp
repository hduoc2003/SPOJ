#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
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
#define fr freopen
#define eb emplace_back
#define ep emplace
#define haid "1."

using namespace std;

const int N = 3e4+1;

int n,m;
int res = 1;
int low[N],num[N];
bool flag[N];
vector < int > ke[N];
stack < pair < int, int > > s;

void enter()
{
    cin >> n >> m;
    int u,v;
    while ( m-- )
    {
        cin >> u >> v;
        ke[u].eb( v );
        ke[v].eb( u );
    }
}

void dfs( int u, int pa )
{
    low[u] = num[u] = ++low[0];
    for ( int& v : ke[u] )
        if ( v != pa )
        {
            s.ep( u, v );
            if ( low[v] )
                low[u] = min( low[u], num[v] );
            else
            {
                dfs( v, u );
                low[u] = min( low[u], low[v] );
                if ( low[v] >= num[u] )
                {
                    int i,j;
                    int cnt = 0;
                    do
                    {
                        i = s.top().first, j = s.top().second;
                        if ( !flag[i] )
                            cnt += flag[i] = 1;
                        if ( !flag[j] )
                            cnt += flag[j] = 1;
                        s.pop();
                    }
                    while ( i != u || j != v );
                    res = max( res, cnt );
                    flag[u] = 0;
                }
            }
        }
}

void solve()
{
    foru( u, 1, n )
        if ( !low[u] )
            dfs( u, 0 );
    cout << res;
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    enter();
    solve();
}
