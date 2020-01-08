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

const int N = 5e4+1, inf = 1e9;

struct node
{
    int sum,best,pre,suf;

    node operator + ( const node& a ) const
    {
        node res;
        res.sum = a.sum + sum;
        res.best = max( max( a.best, best ), suf + a.pre );
        res.pre = max( pre, sum + a.pre );
        res.suf = max( a.suf, a.sum + suf );
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
        for( int i = n-1; i; i-- )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    void modify( int i, int val )
    {
        t[i += n] = { val, val, val, val };
        while ( i >>= 1 )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    T get( int l, int r )
    {
        T resr = { 0, -inf, -inf, -inf }, resl = resr;
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

int n,q;
segtree < node > it;

void enter()
{
    cin >> n;
    it.init( n );
    foru( i, 1, n )
    {
        int x;
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
        bool type;
        int l,r;
        cin >> type >> l >> r;
        if ( type )
            cout << it.get( l, r ).best << '\n';
        else
            it.modify( l, r );
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
