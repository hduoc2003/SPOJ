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

inline int read()
{
    char c = getchar();
    for( ; c < '0'; c = getchar() );
    int x = 0;
    for( ; c >= '0'; c = getchar() )
        x = x * 10 + c - 48;
    return x;
}

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < vector < short > > mat;

mt19937 rd( chrono :: steady_clock :: now().time_since_epoch().count() );

int t,n;
mat a[3];

void operator *= ( mat& res, mat& b )
{
    mat a = res;
    foru( j, 1, n )
    {
        res[1][j] = 0;
        foru( k, 1, n )
            res[1][j] = ( res[1][j] + a[1][k] * b[k][j] ) % 10;
    }
}

void enter()
{
    n = in;
    foru( i, 0, 2 )
    {
        a[i].resize( n+1, vector < short >( n+1 ) );
        foru( j, 1, n )
        {
            foru( k, 1, n )
                a[i][j][k] = getchar() - 48;
            getchar();
        }
    }
}

void solve()
{
    mat c( 2 );
    c[1].resize( n+1 );
    foru( u, 1, 2 )
    {
        foru( i, 1, n )
            c[1][i] = rd() & 1;
        mat d = c;
        c *= a[0], c *= a[1];
        d *= a[2];
        if ( c != d )
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    t = in;
    while ( t-- )
    {
        enter();
        solve();
    }
}
