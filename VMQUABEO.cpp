/*#include <iostream>
#include <fstream>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define fr freopen
#define haid "1."

using namespace std;

const int S = 1e6+1;
int n,l,d;
int log;
int tmin[S][21],tmax[S][21];

inline void is( int& x )
{
    register char c = getchar();
    for( ; c < '0' || c > '9'; c = getchar() );
    x = 0;
    for( ; c >= '0' && c <= '9'; c = getchar() )
        x = x*10+c-48;
}

void enter()
{
    is( n ), is( l ), is( d );
    foru( i, 1, n )
    {
        is( tmin[i][0] );
        tmax[i][0] = tmin[i][0];
    }
}

int log2( const int& x )
{
    return 31 - __builtin_clz( x );
}

int get_min( int l, int r )
{
    return min( tmin[l][log], tmin[r-( 1<<log )+1][log] );
}

int get_max( int l, int r )
{
    return max( tmax[l][log], tmax[r-( 1<<log )+1][log] );
}

void solve()
{
    log = log2( n );
    for( int j = 1; j <= log; j++ )
        for( int i = 1; i + ( 1<<j ) - 1 <= n; i++ )
        {
            tmin[i][j] = min( tmin[i][j-1], tmin[i+( 1<<(j-1) )][j-1] );
            tmax[i][j] = max( tmax[i][j-1], tmax[i+( 1<<(j-1) )][j-1] );
        }
    int j = 1, Min, Max;
    long long res = 0;
    foru( i, ++l, n )
    {
        log = log2( i-j+1 );
        Min = get_min( j, i ), Max = get_max( j, i );
        while ( Max - Min > d && j < i )
        {
            log = log2( i-j );
            Min = get_min( ++j, i );
            Max = get_max( j, i );
        }
        res += max( 0, ( i-l+1 ) - j + 1 );
    }
    cout<<res;
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    fr( haid"INP", "r", stdin );
    enter();
    solve();
}*/
#include <iostream>
#include <fstream>
#include <queue>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define fr freopen
#define haid "1."

using namespace std;

const int S = 1e6+1;
int n,l,d;
int a[S];
deque < int > qmin,qmax;

inline void is( int& x )
{
    register char c = getchar();
    for( ; c < '0' || c > '9'; c = getchar() );
    x = 0;
    for( ; c >= '0' && c <= '9'; c = getchar() )
        x = x*10+c-48;
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    fr( haid"INP", "r", stdin );
    is( n ), is( l ), is( d );
    l++;
    int j = 1;
    long long res = 0;
    foru( i, 1, n )
    {
        is( a[i] );
        while ( qmin.size() && qmin.back() > a[i] )
            qmin.pop_back();
        while ( qmax.size() && qmax.back() < a[i] )
            qmax.pop_back();
        qmin.push_back( a[i] ), qmax.push_back( a[i] );
        while ( qmax.front() - qmin.front() > d )
        {
            if ( qmin.front() == a[j] )
                qmin.pop_front();
            if ( qmax.front() == a[j] )
                qmax.pop_front();
            j++;

        }
        res += max( 0, ( i-l+1 ) - j + 1 );
    }
    cout<<res;
}
