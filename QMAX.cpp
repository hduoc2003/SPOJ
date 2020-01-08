#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
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

template < typename T >
class segtree
{
public:
    int n;
    vector < T > t;

    void init( int _n )
    {
        n = _n;
        t.resize( ++_n << 1 );
    }

    void build()
    {
        for( int i = n; i; i-- )
            t[i] = max( t[i<<1], t[i<<1|1] );
    }

    T get( int l, int r )
    {
        T res{};
        for( l += n, ++r += n; l < r; l >>= 1, r >>= 1 )
        {
            if ( l & 1 )
                res = max( res, t[l++] );
            if ( r & 1 )
                res = max( res, t[--r] );
        }
        return res;
    }
};

const int N = 5e4+1;

int n,m,q;
int a[N];
segtree < int > it;

void enter()
{
    cin >> n >> m;
    while ( m-- )
    {
        int l,r,delta;
        cin >> l >> r >> delta;
        a[l] += delta;
        a[r+1] -= delta;
    }
}

void solve()
{
    it.init( n );
    foru( i, 1, n )
        it.t[i+n] = ( a[i] += a[i-1] );
    it.build();
    cin >> q;
    int l,r;
    while ( q-- )
        cin >> l >> r, cout << it.get( l, r ) << '\n';
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
