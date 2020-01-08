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

const int N = 1e6+1;

int k;
bool d[N];
vector < int > p;

void enter()
{
    cin >> k;
}

void sieve()
{
    foru( i, 2, sqrt( N ) )
        if ( !d[i] )
            for( int j = i*i; j < N; j += i )
                d[j] = true;
    foru( i, 2, N-1 )
        if ( !d[i] )
            p.eb( i );
}

bool ngto( ll x )
{
    for( int i = 0; 1ll*p[i]*p[i] <= x; i++ )
        if ( x % p[i] == 0 )
            return false;
    return true;
}

void solve()
{
    sieve();
    for( int i = 0, n = p.size()-1; i < n; i += 2 )
    {
        int x = p[i+1];
        ll num = p[i];
        while ( x )
            num *= 10, x /= 10;
        num += p[i+1];
        if ( ngto( num ) && !--k )
        {
            cout << num;
            return;
        }
    }
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    enter();
    solve();
}
