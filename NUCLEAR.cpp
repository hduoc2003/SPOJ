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

template < class T > inline void is( T& x )
{
    register char c = getchar();
    for( ; c < 48; c = getchar() );
    x = 0;
    for( ; c >= 48; c = getchar() )
        x = x * 10 + c - 48;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

struct pt
{
    int x,y;
};

struct query
{
    ll r1,r2;
    int id;
};

const int N = 2e5+1;

int n,qr;
int xa,ya,xb,yb;
int res[N];
int bit[N];
pt a[N];
query q[N];
query kqr[N];

void enter()
{
    is( n );
    foru( i, 1, n )
        is( a[i].x ), is( a[i].y );
    is( xa ), is( ya );
    is( xb ), is( yb );
    is( qr );
    foru( i, 1, qr )
    {
        is( q[i].r1 ), is( q[i].r2 );
        q[i].r1 *= q[i].r1;
        q[i].r2 *= q[i].r2;
        q[i].id = i;
    }
}

#define sqr( x ) ( x )*( x )
#define f first
#define s second

ll dis( int& x, int& y, int& xb, int& yb )
{
    return 1ll*sqr( xb - x ) + 1ll*sqr( yb-y );
}

void modify( int i )
{
    for( ; i <= n; i += i & -i )
        bit[i]++;
}

int get( int i )
{
    int res = 0;
    for( ; i; i &= i-1 )
        res += bit[i];
    return res;
}

void kquery()
{
    /// lấy hết điểm <= r2
    vector < pair < ll, int > > k( n+1 );
    foru( i, 1, n )
        k[i] = { kqr[i].r2, kqr[i].id };
    sort( k.begin() + 1, k.end() );
    sort( q+1, q+qr+1, [&]( query& l, query& r ) -> bool
    {
        return l.r2 < r.r2;
    });
    int ptr = 1;
    foru( i, 1, qr )
    {
        while ( ptr <= n && k[ptr].f <= q[i].r2 )
        {
            modify( k[ptr].s );
            ptr++;
        }
        res[q[i].id] += ptr - get( q[i].r1 ) - 1;
    }
}

void init()
{
    foru( i, 1, n )
        kqr[i] = { dis( a[i].x, a[i].y, xa, ya ), dis( a[i].x, a[i].y, xb, yb ) };
    /// sort điểm theo r1
    sort( kqr+1, kqr+n+1, [&]( query& l, query& r ) -> bool
    {
        return l.r1 < r.r1;
    });
    vector < ll > b( n );
    foru( i, 1, n )
    {
        b[i-1] = kqr[i].r1;
        kqr[i].id = i;
    }
    /// lấy hết điểm <= r1
    foru( i, 1, qr )
    {
        res[i] = upper_bound( all( b ), q[i].r1 ) - b.begin();
        /// gán đầu trái cho truy vấn
        q[i].r1 = res[i];
    }
}

void solve()
{
    init();
    kquery();
    foru( i, 1, qr )
        cout << res[i] << '\n';
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
