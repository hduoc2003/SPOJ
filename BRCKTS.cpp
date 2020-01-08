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

    void build( const string& s )
    {
        foru( i, 1, n )
            if ( s[i-1] == ')' )
                t[i+n] = { 0, 1 };
            else
                t[i+n] = { 1, 0 };
        for( int i = n; i; i-- )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    void modify( int i, char c )
    {
        i += n;
        if ( c == ')' )
            t[i] = { 0, 1 };
        else
            t[i] = { 1, 0 };
        while ( i >>= 1 )
            t[i] = t[i<<1] + t[i<<1|1];
    }

    T get( int l, int r )
    {
        T resl = { 0, 0 }, resr = resl;
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
    int open,close;
    node operator + ( const node& a ) const
    {
        int loss = min( open, a.close );
        return { open - loss + a.open, a.close - loss + close };
    }
};

const int N = 3e4+1;

int n,q;
string s;

void enter()
{
    cin >> n >> s >> q;
}

void solve()
{
    segtree < node > it;
    it.init( n );
    it.build( s );
    while ( q-- )
    {
        int type;
        cin >> type;
        if ( type )
            it.modify( type, s[type-1] ^= 1 );
        else
        {
            node res = it.get( 1, n );
            cout << ( !res.open && !res.close ? "YES\n" : "NO\n" );
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );

    #endif
    foru( i, 1, 1 )
    {
        enter();
        cout << "Test " << i << ":\n";
        solve();
    }
}
