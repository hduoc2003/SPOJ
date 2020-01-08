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

const int S = 1e6+1;

int z[S];
string p,t;

void enter()
{
    cin >> t >> p;
}

void solve()
{
    int m = p.size();
    p.push_back( '.' );
    p += t;
    int n = p.size();
    for( int i = 1, l = 0, r = 0; i < n; i++ )
    {
        if ( i <= r )
            z[i] = min( z[i-l], r-i+1 );
        while ( i + z[i] < n && p[z[i]] == p[i+z[i]] )
            z[i]++;
        if ( i + z[i] - 1 > r )
            l = i, r = i + z[i] - 1;
    }
    for( int i = 1; i < n; i++ )
        if ( z[i] == m )
            cout << i-m << " ";
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
