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
#define ep emplace_back
#define haid "1."

using namespace std;

typedef long long ll;

const int N = 1e5+1;

int n,q,t;
ll a[N];
ll bit[N];
int dsu[N];

void modify( int i, ll delta )
{
    for( ; i <= n; i += i & -i )
        bit[i] += delta;
}

ll get( int i )
{
    ll res = 0;
    for( ; i; i &= i-1 )
        res += bit[i];
    return res;
}

void enter()
{
    t++;
    foru( i, 1, n )
    {
        cin >> a[i];
        modify( i, a[i] );
        dsu[i] = i;
    }
    dsu[n+1] = n+1;
    cin >> q;
}

int find( int u )
{
    return dsu[u] != u ? dsu[u] = find( dsu[u] ) : u;
}

void type0( int l, int r )
{
    l = find( l );
    while ( l <= r )
    {
        modify( l, -a[l] );
        modify( l, a[l] = sqrtl( a[l] ) );
        if ( a[l] == 1 )
            dsu[l] = max( l+1, find( l+1 ) );
        l = find( l+1 );
    }
}

void solve()
{
    cout << "Case #" << t << ":\n";
    while ( q-- )
    {
        bool type;
        int l,r;
        cin >> type >> l >> r;
        if ( l > r )
            swap( l, r );
        if ( type )
            cout << get( r ) - get( l-1 ) << '\n';
        else
            type0( l, r );
    }
    cout << '\n';
}

void reset()
{
    fill( bit+1, bit+n+1, 0ll );
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    while ( cin >> n )
    {
        enter();
        solve();
        reset();
    }
}
