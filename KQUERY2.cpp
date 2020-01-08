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
#include <hash_map>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define ep emplace_back
#define haid "1."

using namespace std;

template < class T = int > inline void is( T& x )
{
    register char c = getchar();
    for( ; c < '0'; c = getchar() );
    x = 0;
    for( ; c >= '0'; c = getchar() )
        x = x * 10 + c - 48;
}

const int N = 3e4+1, A = 1e4+1;
const int sqrtN = 175;

int n,q;
int m,sized;
int a[N];
int bit[sqrtN][A];

int block( int& i )
{
    return i/sized + 1 - ( i % sized == 0 );
}

void modify( int i, int& y, int delta )
{
    while ( i <= m )
    {
        int j = y;
        while ( j < A )
        {
            bit[i][j] += delta;
            j += j & -j;
        }
        i += i & -i;
    }
}

int get( int i, int& j )
{
    int res = 0;
    while ( i )
    {
        int tmp = j;
        while ( tmp )
        {
            res += bit[i][tmp];
            tmp &= tmp - 1;
        }
        i &= i - 1;
    }
    return res;
}

void enter()
{
    is( n );
    m = sqrt( n ), sized = n/m + ( n % m != 0 );
    foru( i, 1, n )
    {
        is( a[i] );
        modify( block( i ), a[i], 1 );
    }
    is( q );
}

void solve()
{
    while ( q-- )
    {
        bool type;
        int l,r;
        is( type ), is( l ), is( r );
        if ( !type )
        {
            modify( block( l ), a[l], -1 );
            modify( block( l ), a[l] = r, 1 );
        }
        else
        {
            int k;
            is( k );
            int res = 0;
            while ( l % sized != 1 && l <= r )
                res += a[l++] > k;
            while ( r % sized && l <= r )
                res += a[r--] > k;
            if ( l <= r )
                res += get( block( r ), ++k ) - get( block( r )-1, k );
            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    freopen( "1.INP", "r", stdin );

    enter();
    solve();
}
