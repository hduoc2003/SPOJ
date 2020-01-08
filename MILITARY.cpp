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

const int N = 4001;

#define x first
#define y second

int n;
pair < int, int > p[N];
bool flag[N];
int res;

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> p[i].x >> p[i].y;
}

int ccw( pii& p0, pii& p1, pii& p2 )
{
    int dx1 = p1.x - p0.x, dy1 = p1.y - p0.y;
    int dx2 = p2.x - p0.x, dy2 = p2.y - p0.y;
    int e = dx2*dy1 - dx1*dy2;
    if ( e < 0 )
        return 1;
    return e ? -1 : 0;
}

int convex( vector < int >& c, int x )
{
    foru( i, 1, n )
    {
        if ( flag[i] ) continue;
        while ( c.size() > 1 && ccw( p[c[c.size()-2]], p[c.back()], p[i] )*x <= 0 )
            c.pop_back();
        c.eb( i );
    }
    return c.size();
}

void solve()
{
    sort( p+1, p+n+1 );
    while ( 1 )
    {
        vector < int > up,down;
        if ( convex( up, -1 ) + convex( down, 1 ) - 2 <= 2 )
            cout << res, exit( 0 );
        res++;
        for( int& i : up )
            flag[i] = true;
        for( int& i : down )
            flag[i] = true;
    }
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    ///fr( haid".INP", "r", stdin );

    #endif
    enter();
    solve();
}
