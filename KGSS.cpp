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

const int N = 1e5+1;

int n,q;
int a[N];
int it[N<<2],L[N<<2],R[N<<2];

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> a[i];
    cin >> q;
}

void build( int x, int l, int r )
{
    if ( ( L[x] = l ) == ( R[x] = r ) )
    {
        it[x] = l;
        return;
    }
    int m = ( l + r ) >> 1;
    build( x<<1, l, m );
    build( x<<1|1, m+1, r );
    it[x] = a[it[x<<1]] > a[it[x<<1|1]] ? it[x<<1] : it[x<<1|1];
}

void modify( int x, int i )
{
    if ( L[x] == R[x] )
        return;
    i <= ( L[x] + R[x] ) >> 1 ? modify( x<<1, i ) : modify( x<<1|1, i );
    it[x] = a[it[x<<1]] > a[it[x<<1|1]] ? it[x<<1] : it[x<<1|1];
}

int get( int x, int l, int r )
{
    if ( R[x] < l || L[x] > r || l > r )
        return 0;
    if ( l <= L[x] && R[x] <= r )
        return it[x];
    int i = get( x<<1, l, r ), j = get( x<<1|1, l, r );
    return a[i] > a[j] ? i : j;
}

void solve()
{
    build( 1, 1, n );
    while ( q-- )
    {
        char type;
        int l,r;
        cin >> type >> l >> r;
        if ( type == 'U' )
        {
            a[l] = r;
            modify( 1, l );
        }
        else
        {
            int pos = get( 1, l, r );
            cout << a[pos] + max( a[get( 1, l, pos-1 )], a[get( 1, pos+1, r )] ) << '\n';
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
