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

int t,q;
int z[S];
string s;

void enter()
{
    cin >> s >> q;
}

void solve()
{
    int n = s.size();
    reverse( s.begin(), s.end() );
    z[0] = n;
    for( int i = 1, l = 0, r = 0; i < n; i++ )
    {
        z[i] = 0;
        if ( i <= r )
            z[i] = min( z[i-l], r-i+1 );
        while ( i + z[i] < n && s[z[i]] == s[i+z[i]] )
            z[i]++;
        if ( i + z[i] - 1 > r )
            l = i, r = i + z[i] - 1;
    }
    int x;
    while ( q-- )
        cin >> x, cout << z[n-x] << '\n';
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    cin >> t;
    while ( t-- )
    {
        enter();
        solve();
    }
}
