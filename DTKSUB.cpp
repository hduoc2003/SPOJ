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

const int base = 311, mod = 1e9 + 2277;

int n,k;
long long Hash[50001],p[50001];

void enter()
{
    cin >> n >> k;
    foru( i, 1, n )
    {
        char x;
        cin >> x;
        Hash[i] = ( Hash[i-1] * base + x -'a' + 1 ) % mod;
    }
}

int getHash( int l, int r )
{
    return ( Hash[r] - Hash[l-1]*p[r-l+1] + 1ll*mod*mod ) % mod;
}

bool check( int l )
{
    vector < int > a;
    foru( i, 1, n-l+1 )
        a.ep( getHash( i, i+l-1 ) );
    sort( a.begin(), a.end() );
    int res = 1;
    foru( i, 1, a.size() )
    {
        int cnt = 1;
        while ( a[i] == a[i-1] )
            i++, cnt++;
        if ( cnt > 1 && res < cnt )
            res = cnt, i--;
    }
    return res >= k;
}

void solve()
{
    p[1] = base;
    foru( i, 2, n )
        p[i] = ( p[i-1] * base ) % mod;
    int l = 1, r = n;
    int res = 0;
    while ( l <= r )
    {
        int m = ( l + r ) >> 1;
        if ( check( m ) )
            res = m, l = m + 1;
        else
            r = m-1;
    }
    cout << res;
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
