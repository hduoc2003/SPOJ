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
#define f first
#define s second
#define haid "1."

using namespace std;

template < typename T = int > inline void is( T& x )
{
    register char c = getchar();
    for( ; c < '0' || c > '9'; c = getchar() );
    x = 0;
    for( ; c >= '0' && c <= '9'; c = getchar() )
        x = x*10+c-48;
}

struct query
{
    int l,r,k,id;
    bool operator < ( const query& a ) const
    {
        return a.k < k;
    }
};

const int S = 3e4+1;
const int inf = 2e9;

int n,Q;
pair < int, int > a[S];
query q[(int)2e5+1];
bool flag[S];
int bit[S];
int res[(int)2e5+1];
int b[S];

void enter()
{
    is( n );
    foru( i, 1, n )
        is( a[i].f ), a[i].s = i;
    is( Q );
    foru( i, 1, Q )
    {
        is( q[i].l ), is( q[i].r ), is( q[i].k );
        q[i].id = i;
    }
}

void modify( int i )
{
    for( flag[i] = 1; i <= n; i += i & -i )
        bit[i]++;
}

int Get( int l, int r )
{
    int res = 0;
    while ( l <= r )
    {
        if ( r - ( r & -r ) >= l )
            res += bit[r], r &= r-1;
        else
            res += flag[r--];
    }
    return res;
}

void solve()
{
    sort( q+1, q+Q+1 );
    sort( a+1, a+n+1 );
    foru( i, 1, n )
        b[i] = a[i].f;
    for( int i = 1, j = n+1; i <= Q; i++ )
    {
        int tmp = j;
        j = upper_bound( b+1, b+j, q[i].k ) - b;
        for( int k = j; k < tmp; k++ )
            modify( a[k].s );
        res[q[i].id] = Get( q[i].l, q[i].r );
    }
    foru( i, 1, Q )
        cout << res[i] << '\n';
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid"INP", "r", stdin );
    //fr( haid"OUT", "w", stdout );
    #endif
    enter();
    solve();
}
