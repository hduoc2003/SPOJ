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

const int N = 1e4+1, mod = 1000000007;

int n;
int d[N],p[N];

void enter()
{
    cin >> n;
}

void sieve()
{
    foru( i, 2, N-1 )
        p[i] = i;
    foru( i, 2, N-1 )
        if ( p[i] == i )
            for( int j = i*i; j < N; j += i )
                p[j] = i;
}

void factor( int x )
{
    while ( x > 1 )
    {
        int cnt = 1;
        while ( p[x] == p[x/p[x]] )
            cnt++, x /= p[x];
        maxi( d[p[x]], cnt );
        x /= p[x];
    }
}

int powr( ll a, int b )
{
    ll res = 1;
    while ( b )
    {
        if ( b & 1 )
            res = res * a % mod;
        a = a*a % mod, b >>= 1;
    }
    return res;
}

void solve()
{
    fill( d+1, d+n+1, 0 );
    foru( i, 2, n )
        factor( i );
    ll res = 1;
    foru( i, 2, n )
        res = res * powr( i, d[i] ) % mod;
    cout << res << '\n';
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    int test;
    cin >> test;
    sieve();
    while ( test-- )
    {
        enter();
        solve();
    }
}
