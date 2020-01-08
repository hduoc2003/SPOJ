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
const int S = 5e5+1;

int n;
ll p[S],Hash[S];

void enter()
{
    char x = getchar();
    Hash[n = 1] = x - 'a' + 1;
    while ( 1 )
    {
        x = getchar();
        if ( x == '\n' )
            break;
        Hash[++n] = ( Hash[n-1] * base + x - 'a' + 1 ) % mod;
    }
}

int getHash( const int& l, const int& r )
{
    return ( Hash[r] - Hash[l-1] * p[r-l+1] + 1ll*mod*mod ) % mod;
}

void solve()
{
    int res = n;
    foru( i, 1, n/2 )
    {
        int tmp = getHash( 1, i );
        if ( tmp == getHash( n-i+1, n ) )
        {
            int j = i+1;
            for( ; j <= n-i+1; j++ )
                if ( getHash( j, j+i-1 ) == tmp )
                    break;
            if ( i+1 <= j-1 )
            {
                int hb = getHash( i+1, j-1 );

            }
        }
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
