#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
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

template < class X, class Y >
bool mini( X& a, const Y& b )
{
    if ( a > b ) { a = b; return 1; } return 0;
}

template < class X, class Y >
bool maxi( X& a, const Y& b )
{
    if ( a < b ) { a = b; return 1; } return 0;
}

template < class T >
class segtree
{
public:
    int n,h;
    vector < T > t,lazy;

    void init( int m )
    {
        n = m, h = 32 - __builtin_clz( m );
        t.assign( ++m << 1, 0 ), lazy.assign( m<<1, 0 );
    }

    void calc( int i, int k )
    {
        if ( !lazy[i] )
            t[i] = t[i<<1] + t[i<<1|1];
        else
            t[i] = lazy[i] * k;
    }

    void apply( int i, int val, int k )
    {
        t[i] = val * k;
        if ( i < n )
            lazy[i] = val;
    }

    void upfp( int l, int r )
    {
        int k = 2;
        for( l += n, r += n; l > 1; k <<= 1 )
        {
            l >>= 1, r >>= 1;
            ford( i, r, l )
                calc( i, k );
        }
    }

    void push( int l, int r )
    {
        int  s = h, k = 1 << ( h-1 );
        for( l += n, r += n; s > 0; s--, k >>= 1 )
        {
            for( int i = l >> s; i <= r >> s; i++ )
                if ( lazy[i] )
                {
                    apply( i<<1, lazy[i], k );
                    apply( i<<1|1, lazy[i], k );
                    lazy[i] = 0;
                }
        }
    }

    void modify( int l, int r, int val )
    {
        push( l, l+1 );
        push( r, r+1 );
        bool cl = false, cr = false;
        int k = 1;
        for ( l += n, ++r += n; l < r; l >>= 1, r >>= 1, k <<= 1 )
        {
            if ( cl )
                calc( l-1, k );
            if ( cr )
                calc( r, k );
            if ( l & 1 )
                apply( l++, val, k ), cl = true;
            if ( r & 1 )
                apply( --r, val, k ), cr = true;
        }
        for( --l; r > 0; l >>= 1, r >>= 1, k <<= 1 )
        {
            if ( cl )
                calc( l, k );
            if( cr && ( !cl || l != r ) )
                calc( r, k );
        }
    }

    T get( int l, int r )
    {
        push( l, l+1 );
        push( r, r+1 );
        T res = 0;
        for( l += n, ++r += n; l < r; l >>= 1, r >>= 1 )
        {
            if ( l & 1 )
                res += t[l++];
            if ( r & 1 )
                res += t[--r];
        }
        return res;
    }
};

struct data
{
    int val,id;
    bool type;

    bool operator < ( const data& r ) const
    {
        return val < r.val;
    }
};

const int N = 4e4+1;

int t,n;
int cnt,as;
int x[N],y[N];
data  a[N<<1];
segtree < int > it;

void enter()
{
    cin >> n;
    as = 0;
    foru( i, 1, n )
    {
        int x,y;
        cin >> x >> y;
        a[++as] = { x, i, 0 };
        a[++as] = { y, i, 1 };
    }
}

void compress()
{
    sort( a+1, a+as+1 );
    cnt = -1;
    foru( i, 1, as )
    {
        if ( a[i].val != a[i-1].val )
        {
            cnt++;
            if ( a[i].val != a[i-1].val +1 )
                cnt++;
        }
        a[i].type ? y[a[i].id] = cnt : x[a[i].id] = cnt;
    }
}

void solve()
{
    compress();
    it.init( cnt );
    int res = n;
    ford( i, n , 1 )
    {
        res -= it.get( x[i], y[i] ) > y[i] - x[i];
        it.modify( x[i], y[i], 1 );
    }
    cout << res << '\n';
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP" ,"r", stdin );

    #endif
    a[0].val = N*N;
    cin >> t;
    while ( t-- )
    {
        enter();
        solve();
    }
}
