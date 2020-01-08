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

struct node
{
    int open,close;
};

const int N = 1e5+1;

int n,q;
int l,r,type;
char c;
char a[N];
node t[N<<1];

void enter()
{
    cin >> n >> q >> a+1;
}

node merge( const node& a, const node& b )
{
    node res;
    int loss = min( a.open, b.close );
    res.open = a.open - loss + b.open;
    res.close = b.close - loss + a.close;
    return res;
}

void build()
{
    foru( i, 1, n )
    {
        if ( a[i] == ')' )
            t[i+n] = { 0, 1 };
        else
            t[i+n] = { 1, 0 };
    }
    ford( i, n, 1 )
        t[i] = merge( t[i<<1], t[i<<1|1] );
}

void modify( int i )
{
    i += n;
    if ( c == ')' )
        t[i] = { 0, 1 };
    else
        t[i] = { 1, 0 };
    for( ; i > 1; i >>= 1 )
    {
        int j = min( i, i^1 );
        t[i>>1] = merge( t[j], t[j^1] );
    }
}

node get()
{
    node resl = { 0, 0 }, resr = resl;
    for( l += n, ++r += n; l < r; l >>= 1, r >>= 1 )
    {
        if ( l & 1 )
            resl = merge( resl, t[l++] );
        if ( r & 1 )
            resr = merge( t[--r], resr );
    }
    return merge( resl, resr );
}


void solve()
{
    build();
    while ( q-- )
    {
        cin >> type >> l;
        if ( type )
        {
            cin >> r;
            node res = get();
            cout << ( !res.open && !res.close );
        }
        else
        {
            cin >> c;
            if ( a[l] != c )
                modify( l ), a[l] = c;
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
