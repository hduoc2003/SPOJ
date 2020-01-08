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

typedef const int& ci;
typedef long long ll;
typedef pair < double, double > pii;

struct data
{
    double x,y;
    int id;

    bool operator < ( const data& r ) const
    {
        return y < r.y || ( y == r.y && x < r.x ) || ( y == r.y && x == r.x && id < r.id );
    }
};

const int N = 5e4+1;

int n;
data a[N];

void enter()
{
    cin >> n;
    foru( i, 1, n )
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
}

void init()
{
    sort( a+1, a+n+1, [&]( data& l, data& r ) -> bool
    {
        return l.x < r.x;
    });
}

void sweep_line()
{
    auto sqr = [&]( double a ) -> double
    {
        return a*a;
    };
    set < data > box;
    int ptr = 1;
    int s,f;
    double res = 1e12;
    foru( i, 1, n )
    {
        while ( a[i].x - res > a[ptr].x )
            box.erase( a[ptr++] );
        auto it = box.lower_bound( { a[i].y - res, a[i].x - res, a[i].id } );
        while ( it != box.end() && a[i].y + res >= it->y )
        {
            double tmp = sqr( a[i].y - it->y ) + sqr( a[i].x - it->x );
            if ( res > tmp )
            {
                s = a[i].id, f = it->id;
                res = tmp;
            }
            it++;
        }
        box.insert( a[i] );
    }
    if ( s > f )
        swap( s, f );
    cout << --s << " " << --f;
    cout << fixed << setprecision( 6 ) << " " << sqrtl( res );
}

int main()
{
    #define haid "1."

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    enter();
    init();
    sweep_line();
}
