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
#include <numeric>
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

const int N = 1e4+1, S = 1e5+2;
const int mod = 5000000;

int n,k;
int smax;
vector < int > a;
int bit[S];

void enter()
{
    cin >> n >> k;
    a.resize( n );
    for( int& i : a )
    {
        cin >> i;
        smax = max( smax, ++i );
    }
}

void modify( int i, int delta )
{
    for( ; i <= smax; i += i & -i )
    {
        bit[i] += delta;
        bit[i] %= mod;
    }
}

int get( int i )
{
    int res = 0;
    for( ; i; i &= i-1 )
    {
        res += bit[i];
        res %= mod;
    }
    return res;
}

void solve()
{
    vector < int > cnt( n, 1 );
    foru( j, 2, k )
    {
        fill( bit+1, bit+smax+1, 0 );
        for( int i = 0; i < n; i++ )
        {
            if ( cnt[i] )
                modify( a[i], cnt[i] );
            cnt[i] = get( a[i]-1 );
        }
    }
    cout << accumulate( cnt.begin()+1, cnt.end(), 0ll ) % mod;
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
