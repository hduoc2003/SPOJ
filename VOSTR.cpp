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

int n,m,q;
int a,b,c,d;
char s[S],t[S];
long long Hashs[S],Hasht[S];
long long p[S];

void enter()
{
    cin >> n >> m;
    foru( i, 1, n )
    {
        cin >> s[i];
        Hashs[i] = ( Hashs[i-1] * base + s[i] ) % mod;
    }
    foru( i, 1, m )
    {
        cin >> t[i];
        Hasht[i] = ( Hasht[i-1] * base + t[i] ) % mod;
    }
}

int getHash( int l, int r, long long *Hash )
{
    return ( Hash[r] - Hash[l-1]*p[r-l+1] + 1ll*mod*mod ) % mod;
}

char compare()
{
    int l = 1, r = min( b-a, d-c ) + 1, k = r;
    int tmp = 0;
    while ( l <= r )
    {
        int m = ( l + r ) >> 1;
        if ( getHash( a, a+m-1, Hashs ) == getHash( c, c+m-1, Hasht ) )
            tmp = m, l = ++m;
        else
            r = --m;
    }
    if ( tmp < k )
        return s[a+tmp] < t[c+tmp] ? '<' : '>';
    return d-c > b-a ? '<' : ( d-c < b-a ? '>' : '=' );
}

void solve()
{
    p[1] = base;
    foru( i, 2, 1000000 )
        p[i] = ( p[i-1] * base ) % mod;
    cin >> q;
    while ( q-- )
    {
        cin >> a >> b >> c >> d;
        cout << compare();
    }
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
