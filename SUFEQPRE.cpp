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

const int base = 311, mod = 1e9+2277;
const int S = 1e6+1;

int t,n;
string s;
ll p[S],Hash[S];

void enter()
{
    getline( cin, s );
    n = s.size();
    s = " " + s;
    foru( i, 1, n )
        Hash[i] = ( Hash[i-1] * base + s[i] - 'a' + 1 ) % mod;
}

int getHash( const int& l, const int& r )
{
    return ( Hash[r] - Hash[l-1]*p[r-l+1] + 1ll*mod*mod ) % mod;
}

int solve()
{
    int res = 0;
    for( int i = 1; i < n; i++ )
        res += Hash[i] == getHash( n-i+1, n );
    return res;
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    cin >> t;
    p[1] = base;
    foru( i, 2, 1000000 )
        p[i] = ( p[i-1] * base ) % mod;
    cin.ignore( 1 );
    foru( i, 1, t )
    {
        enter();
        cout << "Case " << i << ": " << solve() << '\n';
    }
}
