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
#define all( a ) a.begin(), a.end()
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

const int N = 1e5+1;

typedef int mang[N<<2];

int test,n,q;
int type,l,r,val;
int a[N];
mang L,R;
mang lazy,flag;
mang t;
long long tsqr[N<<2];

void enter()
{
    cin >> n >> q;
    foru( i, 1, n )
        cin >> a[i];
}

void build( int x, int l, int r )
{
    if ( ( L[x] = l ) == ( R[x] = r ) )
    {
        t[x] = a[l];
        tsqr[x] = a[l] * a[l];
        return;
    }
    int m = ( l + r ) >> 1, i = x << 1, j = i + 1;
    build( i, l, m );
    build( j, m+1, r );
    t[x] = t[i] + t[j];
    tsqr[x] = tsqr[i] + tsqr[j];
}

int len( int x )
{
    return R[x] - L[x] + 1;
}

void down( int x )
{
    if ( L[x] < R[x] )
    {
        int l = x << 1, r = l + 1;
        if ( lazy[x] )
        {
            int tmp = lazy[x];
            lazy[l] += tmp, lazy[r] += tmp;
            flag[l] = flag[r] = lazy[x] = 0;
            tsqr[l] += tmp * tmp * len( l ) + 2 * tmp * t[l];
            tsqr[r] += tmp * tmp * len( r ) + 2 * tmp * t[r];
            t[l] += tmp * len( l );
            t[r] += tmp * len( r );
            return;
        }
        if ( flag[x] )
        {
            int tmp = flag[x];
            flag[l] = flag[r] = tmp;
            lazy[l] = lazy[r] = flag[x] = 0;
            tsqr[l] = tmp * tmp * len( l );
            tsqr[r] = tmp * tmp * len( r );
            t[l] = tmp * len( l );
            t[r] = tmp * len( r );
        }
    }
}

void modify( int x )
{
    if ( R[x] < l || L[x] > r )
        return;
    down( x );
    if ( l <= L[x] && R[x] <= r )
    {
        if ( type )
        {
            lazy[x] += val;
            tsqr[x] += val * val * len( x ) + 2 * val * t[x];
            t[x] += val * len( x );
            flag[x] = 0;
        }
        else
        {
            flag[x] = val;
            tsqr[x] = val * val* len( x );
            t[x] = val * len( x );
            lazy[x] = 0;
        }
        return;
    }
    int i = x << 1, j = i + 1;
    modify( i ), modify( j );
    tsqr[x] = tsqr[i] + tsqr[j];
    t[x] = t[i] + t[j];
}

ll get( int x )
{
    if ( R[x] < l || L[x] > r )
        return 0;
    down( x );
    if ( l <= L[x] && R[x] <= r )
        return tsqr[x];
    return get( x << 1 ) + get( x << 1 | 1 );
}

void solve()
{
    build( 1, 1, n );
    while ( q-- )
    {
        cin >> type >> l >> r;
        if ( type == 2 )
            cout << get( 1 ) << '\n';
        else
        {
            cin >> val;
            modify( 1 );
        }
    }
}

int main()
{
    #define haid "1."

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );
    fr( "2.OUT", "w", stdout );
    #endif
    cin >> test;
    foru( i, 1, test )
    {
        cout << "Case " << i << ":\n";
        enter();
        solve();
    }
}
