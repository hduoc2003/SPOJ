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

const int N = 1e5+1;

int n;
pair < int, int > a[N];

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> a[i].f >> a[i].s;
}

void solve()
{
    sort( a+1, a+n+1, [&]( const pair < int, int >& x, const pair < int, int >& y )
    {
        return x.f < y.f || ( x.f == y.f && x.s > y.s );
    });
    vector < int > b( n+1, 1e9 );
    b[0] = -1e9;
    int res = 0;
    ford( i, n, 1 )
    {
        int j = upper_bound( b.begin(), b.end(), a[i].s ) - b.begin();
        res = max( res, j );
        b[j] = a[i].s;
    }
    cout << res;
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
