#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <bitset>
#include <tuple>
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
#define rall( a ) a.rbegin(), a.rend()
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
typedef vector < vector < ll > > mtx;

const ll mod = 1e15 + 7;

ll mul( ll a, ll k )
{
    ll res = 0;
    while ( k )
    {
        if ( k & 1ll )
            res = ( res + a ) % mod;
        a = ( a << 1 ) % mod;
        k >>= 1;
    }
    return res;
}

void operator *= ( mtx& res, mtx b )
{
    mtx a = res;
    foru( i, 0, 3 )
        foru( j, 0, 3 )
        {
            res[i][j] = 0;
            foru( k, 0, 3 )
                res[i][j] = ( res[i][j] + mul( a[i][k], b[k][j] ) ) % mod;
        }
}

int t,n;
mtx a = { { 0, 1, 0, 0 },
          { 0, 0, 1, 0 },
          { 1, 1, 1, 0 },
          { 1, 1, 1, 1 }
        };
mtx res;

void powmtx( int k )
{
    mtx b = a;
    while ( k )
    {
        if ( k & 1 )
            res *= b;
        b *= b;
        k >>= 1;
    }
}

void solve()
{
    cin >> t;
    while ( t-- )
    {
        cin >> n;
        if ( n <= 3 )
            cout << n*( n+1 )/2 << '\n';
        else
        {
            res = a;
            powmtx( n - 4 );
            ll ans = 0;
            foru( i, 0, 2 )
                ans += res[3][i] * ( i + 1 );
            cout << ( ans + res[3][3] * 6 ) % mod << '\n';
        }
    }
}

int main()
{
    #define haid "1."

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    solve();
}
