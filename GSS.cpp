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
#include <bitset>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define ep emplace_back
#define haid "1."

using namespace std;

template < class T >
class segtree
{
public:
    int n;
    vector < T > t;

    void init( int m )
    {
        n = m;
        t.resize( ++m << 1 );
    }

    void build( const int *a )
    {
        foru( i, 1, n )
            t[i+n] = { a[i] - a[i-1], a[i-1], a[i] };
        ford( i, n, 1 )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    T get( int l, int r )
    {
        T resl = { INT_MIN, 1<<30, -( 1<<30 ) }, resr = resl;
        for( l += n, ++r += n; l < r; l >>= 1, r >>= 1 )
        {
            if ( l & 1 )
                resl = resl + t[l++];
            if ( r & 1 )
                resr = t[--r] + resr;
        }
        return resl + resr;
    }
};

struct node
{
    int res,Min,Max;
    node operator + ( const node& a ) const
    {
        int tmp = max( res, a.res );
        return { max( tmp, a.Max - Min ), min( a.Min, Min ), max( a.Max, Max ) };
    }
};

const int N = 5e4+1, inf = 1e9;

int n,q;
int a[N];
segtree < node > it;

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> a[i], a[i] += a[i-1];
    cin >> q;
}

void solve()
{
    it.init( n );
    it.build( a );
    int l,r;
    /*while ( q-- )
        cin >> l >> r, cout << it.get( l, r ).res << '\n';*/
    auto p = [&]( node a )
    {
        cout << a.res << " " << a.Min << " " << a.Max << endl;
    };
    for( auto k : it.t )
        p( k );
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
