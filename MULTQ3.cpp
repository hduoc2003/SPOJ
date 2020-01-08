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

struct node
{
    int zero,one,two;

    node operator + ( const node& a ) const
    {
        return { zero + a.zero, one + a.one, two + a.two };
    }
};

const int N = 1e5+1;

int n,q;
int L[N<<2],R[N<<2];
int lazy[N<<2];
node it[N<<2];

void build( int x, int l, int r )
{
    if ( ( L[x] = l ) == ( R[x] = r ) )
    {
        it[x] = { 1, 0, 0 };
        return;
    }
    int m = ( l + r ) >> 1;
    build( x<<1, l, m );
    build( x<<1|1, m+1, r );
    it[x] = it[x<<1] + it[x<<1|1];
}

void apply1( int x )
{
    //cout << x << " ";
    it[x] = { it[x].two, it[x].zero, it[x].one };
}

void apply2( int x )
{
    it[x] = { it[x].one, it[x].two, it[x].zero };
}

void down( int x )
{
    if ( lazy[x] && L[x] < R[x] )
    {
        int tmp = lazy[x];
        int l = x<<1, r = x<<1|1;
        if ( tmp == 1 )
            apply1( l ), apply1( r );
        else
            apply2( l ), apply2( r );
        lazy[l] = ( lazy[l] + tmp ) % 3;
        lazy[r] = ( lazy[r] + tmp ) % 3;
        lazy[x] = 0;
    }
}

void modify( int x, int l, int r )
{
    if ( R[x] < l || L[x] > r )
        return;
    down( x );
    if ( l <= L[x] && R[x] <= r )
    {
        lazy[x] = 1;
        return apply1( x );
    }
    modify( x<<1, l, r );
    modify( x<<1|1, l, r );
    it[x] = it[x<<1] + it[x<<1|1];
}

int get( int x, int l, int r )
{
    if ( R[x] < l || L[x] > r )
        return 0;
    down( x );
    if ( l <= L[x] && R[x] <= r )
        return it[x].zero;
    return get( x<<1, l, r ) + get( x<<1|1, l, r );
}

void solve()
{
    cin >> n >> q;
    build( 1, 1, n );
    while ( q-- )
    {
        int type,l,r;
        cin >> type >> l >> r;
        l++, r++;
        if ( type )
            cout << get( 1, l, r ) << '\n';
        else
            modify( 1, l, r );
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
