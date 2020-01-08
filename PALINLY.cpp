#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <array>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define ep emplace_back
#define haid "1."

using namespace std;

typedef long long ll;

const int base = 311, mod = 1e9 + 2277;

int n;
ll Hash[50001],p[50001];

void enter()
{
    cin >> n;
    foru( i, 1, n )
    {
        char x;
        cin >> x;
        Hash[i] = ( Hash[i-1] * base + x - 'a' + 1 ) % mod;
    }
}

int getHash( int l, int r )
{
    return ( Hash[r] - 1ll*Hash[l-1]*p[r-l+1] + 1ll*mod*mod ) % mod;
}

int check( int l )
{
    int res = -1;
    foru( i, l, n-l )
    {
        if ( getHash( i-l+1, i ) == getHash( i+1, i+l ) )
            res = 0;
        if ( i-l > 0 && getHash( i-l, i-1 ) == getHash( i+1, i+l ) )
            return 1;
    }
    return res;
}

void solve()
{
    p[1] = base;
    foru( i, 2, n )
        p[i] = ( p[i-1] * base ) % mod;
    int l = 1, r = n >> 1;
    int res = 1;
    while ( l <= r )
    {
        int m = ( l + r ) >> 1;
        int tmp = check( m );
        if ( tmp != -1 )
            res = m << 1 | tmp, l = m+1;
        else
            r = m-1;
    }
    cout << res;
}

signed main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    enter();
    solve();
}
