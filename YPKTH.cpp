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

template < class T = int > inline void is( T& x )
{
    register char c = getchar();
    register bool sign = false;
    for( ; c < '0'; c = getchar() )
        if ( c == '-' )
            sign = true;
    x = 0;
    for( ; c >= '0'; c = getchar() )
        x = x * 10 + c - 48;
    if ( sign )
        x = -x;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > node;

const int N = 1e5+1;

int n,q;
int l,r,k;
node t[N<<1];

void enter()
{
    is( n );
    int x;
    foru( i, 1, n )
    {
        is( x );
        t[i+n].eb( x );
    }
    is( q );
}

void merge( node& res, node& l, node& r )
{
    node :: iterator it = r.begin();
    for( int& i : l )
    {
        while ( it != r.end() && *it < i )
            res.eb( *it++ );
        res.eb( i );
    }
    while ( it != r.end() )
        res.eb( *it++ );
}

void build()
{
    ford( i, n, 1 )
        merge( t[i], t[i<<1], t[i<<1|1] );
}

int get( int& val )
{
    int res = 0;
    int i = l, j = r;
    for ( i += n, ++j += n; i < j; i >>= 1, j >>= 1 )
    {
        if ( i & 1 )
        {
            res += lower_bound( all( t[i] ), val ) - t[i].begin();
            i++;
        }
        if ( j & 1 )
        {
            j--;
            res += lower_bound( all( t[j] ), val ) - t[j].begin();
        }
    }
    return res;
}

void solve()
{
    build();
    while ( q-- )
    {
        is( l ), is( r ), is( k );
        int L = 0, R = n-1, res;
        while ( L <= R )
        {
            int m = ( L + R ) >> 1;
            if ( get( t[1][m] ) < k )
                res = t[1][m], L = ++m;
            else
                R = --m;
        }
        cout << res << '\n';
    }
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
