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

const int N = 1e6+1;

int n;
int phi[N];
long long res[N];

void enter()
{

}

void init()
{
    foru( i, 1, N-1 )
        phi[i] = i;
    foru( i, 2, N-1 )
        if ( phi[i] == i )
            for( int j = i; j < N; j += i )
                phi[j] -= phi[j] / i;
    foru( i, 1, N-1 )
        for( int j = 2; j*i < N; j++ )
            res[i*j] += i * phi[j];
    foru( i, 2, N-1 )
        res[i] += res[i-1];
}

void solve()
{

}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    init();
    while ( cin >> n )
    {
        if ( !n ) return 0;
        cout << res[n] << '\n';
    }
}
