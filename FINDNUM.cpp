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
typedef unsigned long long ll;
typedef pair < int, int > pii;

const int N = 1001;
const long double inf = 1e18;

int n;
long double dp[N][11];
int p[] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void enter()
{
    cin >> n;
}

void solve()
{
    fill( dp[1], dp[1]+11, 1 );
    foru( i, 2, n )
    {
        dp[i][0] = inf;
        foru( j, 1, 10 )
        {
            dp[i][j] = dp[i][j-1];
            int k = 1;
            for( long double pr = p[j]; pr <= inf; k++, pr *= p[j] )
                if ( i % ( k+1 ) == 0 )
                    mini( dp[i][j], dp[i/(k+1)][j-1] * pr );
        }
    }
    ll res = inf;
    foru( i, 0, 10 )
        if ( dp[n][i] )
            mini( res, dp[n][i] );
    cout << res;
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
