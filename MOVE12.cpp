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

const int N = 1e4+5;

int n;
int c[N],t[N];

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> c[i] >> t[i];
}

#define l first
#define r second

bool check( int mid )
{
    vector < pair < int, int > > a;
    foru( i, 1, n )
        a.eb( c[i] - mid / t[i], c[i] + mid / t[i] );
    sort( all( a ) );
    priority_queue < int, vector < int >, greater < int > > q;
    for( int i = 1, j = 0; i <= n; i++ )
    {
        while ( j < n && a[j].l <= i )
        {
            if ( a[j].r >= i )
                q.ep( a[j].r );
            j++;
        }
        while ( q.size() && q.top() < i )
            q.pop();
        if ( q.empty() )
            return false;
        q.pop();
    }
    return true;
}

void solve()
{
    int l = 0, r = 1e8;
    int res;
    while ( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if ( check( mid ) )
            res = mid, r = --mid;
        else
            l = ++mid;
    }
    cout << res;
}

int main()
{
    #define haid ""

    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    #ifndef ONLINE_JUDGE
    fr( haid".INP", "r", stdin );

    #endif
    enter();
    solve();
}
