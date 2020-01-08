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

struct node
{
    int sum,best,pre,suf;

    node operator + ( const node& r ) const
    {
        node res;
        res.sum = sum + r.sum;
        res.best = max( max( best, r.best ), suf + r.pre );
        res.pre = max( pre, sum + r.pre );
        res.suf = max( r.suf, r.sum + suf );
        return res;
    }
};

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

    void build()
    {
        ford( i, n-1, 1 )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    T get( int l, int r )
    {
        if ( l > r )
            return t[0];
        node resr = { 0, -1<<30, -1<<30, -1<<30 }, resl = resr;
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

const int N = 1e4+1;

int t,n,q;
segtree < node > it;

void enter()
{
    cin >> n;
    it.init( n );
    int x;
    foru( i, 1, n )
    {
        cin >> x;
        it.t[i+n] = { x, x, x, x };
    }
    cin >> q;
}

void solve()
{
    it.build();
    while ( q-- )
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res;
        if ( y1 < x2 )
            res = it.get( x1, y1 ).suf + it.get( y1+1, x2-1 ).sum + it.get( x2, y2 ).pre;
        else
        {
            res = it.get( x2, y1 ).best;
            int x = max( it.get( x1, x2-1 ).suf, 0 );
            res = max( res, x + it.get( x2, y2 ).pre );
            x = max( it.get( y1+1, y2 ).pre, 0 );
            res = max( res, it.get( x1, y1 ).suf + x );
        }
        cout << res << '\n';
    }
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
