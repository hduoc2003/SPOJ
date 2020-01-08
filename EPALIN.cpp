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
const int S = 1e6+1;

int n,m;
string a,b;
long long ha[S],hb[S];
long long p[S];

int getHash( int l, int r, long long Hash[] )
{
    return ( Hash[r] - Hash[l-1]*p[r-l+1] + 1ll*mod*mod ) % mod;
}

void solve()
{
    b = a;
    reverse( b.begin(), b.end() );
    n = a.size();
    foru( i, 1, n )
    {
        ha[i] = ( ha[i-1] * base + a[i-1] ) % mod;
        hb[i] = ( hb[i-1] * base + b[i-1] ) % mod;
    }
    int k = 0;
    foru( i, 1, n )
        if ( getHash( n-i+1, n, ha ) == getHash( 1, i, hb ) )
            k = i;
    cout << a;
    while ( k < n )
        cout << b[k++];
    cout << '\n';
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    p[1] = base;
    foru( i, 2, 1000000 )
        p[i] = ( p[i-1] * base ) % mod;
    while ( cin >> a )
        solve();
}
