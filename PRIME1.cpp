#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <tuple>
#include <chrono>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <array>
#include <bitset>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a, _b = b; i <= _b; i++ )
#define ford( i, a, b ) for( int i = a; i >= (b); i-- )
#define all( a ) a.begin(), a.end()
#define rall( a ) a.rbegin(), a.rend()
#define fr freopen
#define eb emplace_back
#define ep emplace
#define in read()

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

typedef const int& ci;
typedef long long ll;
typedef pair < int, int > pii;

const int N = sqrt( 2e9 );

int l,r;
int test;
bool d[N];
vector < int > p;

void enter()
{
    cin >> l >> r;
}

void init()
{
    foru( i, 2, N-1 )
        if ( !d[i] )
        {
            p.eb( i );
            for( int j = i << 1; j < N; j += i )
                d[j] = true;
        }
}

bool is_prime( int x )
{
    for( int i = 0; p[i]*p[i] <= x; i++ )
        if ( x % p[i] == 0 )
            return false;
    return true;
}

void solve()
{
    maxi( l, 2 );
    while ( l <= r )
    {
        if ( is_prime( l ) )
            cout << l << "\n";
        l++;
    }
    cout << '\n';
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    cin >> test;
    init();
    while ( test-- )
    {
        enter();
        solve();
    }
}
