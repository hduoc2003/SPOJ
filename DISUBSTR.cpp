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
const int S = 1001;

int t,n;
string s;
ll Hash[S],p[S];

void enter()
{
    cin >> s;
}

int getHash( int l, int r )
{
    return ( Hash[r] - Hash[l-1]*p[r-l+1] + 1ll*mod*mod ) % mod;
}

void solve()
{
    n = s.size(), s = " " + s;
    foru( i, 1, n )
        Hash[i] = ( Hash[i-1]*base + s[i] ) % mod;
    int res = 0;
    foru( l, 1, n )
    {
        set < int > a;
        foru( i, 1, n-l+1 )
            a.insert( getHash( i, i+l-1 ) );
        res += a.size();
    }
    cout << res << '\n';
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    cin >> t;
    p[1] = base;
    foru( i, 2, 1000 )
        p[i] = ( p[i-1]*base ) % mod;
    while ( t-- )
    {
        enter();
        solve();
    }
}
