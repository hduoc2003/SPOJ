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
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define ep emplace_back
#define haid "1."

using namespace std;

const int N = 2e5+1;

int n,q;
bool type;
int l,r,delta;
int L[N],R[N];
int lazy[N];
int t[N];

void build( int x, int l, int r )
{
    if ( ( L[x] = l ) == ( R[x] = r ) )
        return;
    int m = ( l + r ) >> 1;
    build( x<<1, l, m );
    build( x<<1|1, m+1, r );
}

void down( int x )
{
    if ( lazy[x] && L[x] < R[x] )
    {
        int tmp = lazy[x];
        t[x<<1] += tmp;
        t[x<<1|1] += tmp;
        lazy[x<<1] += tmp;
        lazy[x<<1|1] += tmp;
        lazy[x] = 0;
    }
}

void modify( int x )
{
    down( x );
    if ( L[x] > r || R[x] < l )
        return;
    if ( l <= L[x] && R[x] <= r )
    {
        lazy[x] = delta;
        t[x] += delta;
        return;
    }
    modify( x<<1 );
    modify( x<<1|1 );
    t[x] = max( t[x<<1], t[x<<1|1] );
}

int get( int x )
{
    down( x );
    if ( L[x] > r || R[x] < l )
        return 0;
    if ( l <= L[x] && R[x] <= r )
        return t[x];
    return max( get( x<<1 ), get( x<<1|1 ) );
}

void solve()
{
    cin >> n >> q;
    build( 1, 1, n );
    while ( q-- )
    {
        cin >> type >> l >> r;
        if ( type )
            cout << get( 1 ) << '\n';
        else
        {
            cin >> delta;
            modify( 1 );
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    solve();
}
