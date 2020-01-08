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

const int N = 1e4+1, mod = 5000000;

template < typename T >
class fenwick
{
public :
    int n;
    vector < T > bit;
    fenwick( int _n ): n( _n ), bit( _n+2, 0 ) {}

    void modify( int i, const T& delta )
    {
        for( ; i <= n; i += i & -i )
        {
            bit[i] += delta;
            bit[i] %= mod;
        }
    }

    T get( int i )
    {
        T res = 0;
        for( ;i; i &= i-1 )
        {
            res += bit[i];
            res %= mod;
        }
        return res;
    }

    void reset()
    {
        fill( bit.begin(), bit.end(), 0 );
    }
};

int n,k;
vector < int > a;

void enter()
{
    cin >> n >> k;
    a.resize( n );
    for( int& i : a )
        cin >> i;
}

void solve()
{
    fenwick < int > bit( n );
    vector < int > cnt( n+1, 1 );
    foru( j, 2, k )
    {
        for( const int& x : a )
        {
            if ( cnt[x] )
                bit.modify( x, cnt[x] );
            cnt[x] = bit.get( x-1 );
        }
        bit.reset();
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
