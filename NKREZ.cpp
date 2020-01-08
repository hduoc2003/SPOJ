#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
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
#define ep emplace_back
#define s first
#define f second
#define haid "1."

using namespace std;

const int N = 1e4+1, A = 3e4+1;

int n;
pair < int, int > a[N];
int bit[A];
int dp[A];

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> a[i].f >> a[i].s;
}

void modify( int i, int x )
{
    for( ; i < A; i += i & -i )
        bit[i] = max( bit[i], x );
}

int get( int i )
{
    int res = 0;
    for( ; i; i &= i-1 )
        res = max( res, bit[i] );
    return res;
}

void solve()
{
    sort( a+1, a+n+1 );
    foru( i, 1, n )
    {
        modify( a[i].s, dp[a[i].s] = get( a[i].f ) + a[i].s - a[i].f );
    }
    cout << *max_element( dp+1, dp+A );
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    enter();
    solve();
}
