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

const int N = 101;

int n;
int d[N];
int adj[2][N];
int dp[N][8][8];
long long g[N][8][8];

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> d[i], d[i] = 1 << 3 - d[i];
}

bool ok( int mask, int other, int t )
{
    return !((mask << 3-t) & other ) && !((mask >> 3-t) & other);
}

bool ok( int mask, int i )
{
    return !( mask & d[i] );
}

void solve()
{
    #define cb( x ) __builtin_popcount( x )

    foru( mask, 0, 7 )
        if ( ok( mask, 1 ) )
        {
            dp[1][0][mask] = cb( mask );
            g[1][0][mask] = 1;
        }
    foru( i, 2, n )
        foru( t1, 0, 7 )
            foru( t2, 0, 7 )
                if ( ok( t1, t2, 1 ) && ok( t1, i-1 ) && ok( t2, i ) )
                {
                    int c2 = cb( t2 );
                    int& F = dp[i][t1][t2];
                    ll& G = g[i][t1][t2];
                    foru( t, 0, 7 )
                        if ( ok( t, t1, 1 ) && ok( t, t2, 2 ) )
                        {
                            if ( maxi( F, dp[i-1][t][t1] + c2 ) )
                                G = g[i-1][t][t1];
                            else
                                if ( F == dp[i-1][t][t1] + c2 )
                                    G += g[i-1][t][t1];
                        }
                }
    int Max = 0;
    ll s = 0;
    foru( t1, 0, 7 ) foru( t2, 0, 7 )
        if ( maxi( Max, dp[n][t1][t2] ) )
            s = g[n][t1][t2];
        else
            if ( Max == dp[n][t1][t2] )
                s += g[n][t1][t2];
    cout << Max << " " << s;
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
