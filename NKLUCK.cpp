#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define fr freopen
#define ep emplace_back
#define f first
#define id second
#define haid "1."

using namespace std;

const int N = 5e5+1;

template < typename T > inline void is( T& x )
{
    register char c = getchar();
    for( ; c < '0' || c > '9'; c = getchar() );
    x = 0;
    for( ; c >= '0' && c <= '9'; c = getchar() )
        x = x * 10 + c - 48;
}

int n,k;
int x[N];
pair < int, int > a[N];
int bit[N];
int b[N];

void enter()
{
    is( n ), is( k );
    foru( i, 1, n )
        is( x[i] );
}

void modify( int i )
{
    for( ; i <= n; i += i & -i )
        bit[i]++;
}

int get( int i )
{
    int res = 0;
    for( ; i; i &= i-1 )
        res += bit[i];
    return res;
}

void init( int k )
{
    a[0] = { 0, 0 };
    int s = 0;
    foru( i, 1, n )
    {
        s += x[i] >= k;
        a[i].f = 2*s - i;
        a[i].id = i;
    }
}

void compress()
{
    sort( a, a+n+1 );
    int s = 1;
    b[a[0].id] = s;
    foru( i, 1, n )
    {
        bit[i] = 0;
        s += a[i].f != a[i-1].f;
        b[a[i].id] = s;
    }
}

long long ans( int k )
{
    init( k );
    compress();
    long long res = 0;
    foru( i, 0, n )
    {
        res += get( b[i] );
        modify( b[i] );
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
   // fr( haid"INP", "r", stdin );

    #endif // ONLINE_JUDGE
    enter();
    double tmp = 1ll*n*( n+1 )/2;
    cout << ( double )( ans( k ) - ans( k+1 ) )/tmp;
}
