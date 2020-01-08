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

const int N = 2001;
const int ok = (1<<1) | (1<<8) | (1<<9);

int n;
int a[N];
int dp[N][1<<10];

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> a[i];
}

void solve()
{
    sort( a+1, a+n+1 );
    dp[1][1] = 1;
    foru( i, 2, n )
    {
        int d = a[i] - a[i-1];
        foru( mask, 0, 1023 )
        {
            int other = d < 10 ? ( mask << d ) & 1023 : 0;
            maxi( dp[i][other], dp[i-1][mask] );
            if ( ( other & ok ) == 0 )
                maxi( dp[i][other|1], dp[i-1][mask]+1 );
        }
    }
    cout << n - *max_element( dp[n], dp[n]+1024 );
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
