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
#define f first
#define id second
#define haid "1."

using namespace std;

const int N = 1e5+1;

int n,p;
pair < int, int > a[N];
int s[N];
int idx[N];

void enter()
{
    cin >> n >> p;
    foru( i, 1, n )
    {
        cin >> a[i].f, a[i].f += a[i-1].f;
        a[i].id = i;
        a[i+n].id = i+n;
        a[i+n].f = a[i].f - p;
    }
}

void compress()
{
    sort( a, a+2*n+1 );
    int cnt = 1;
    s[a[0].id] = 1;
    foru( i, 1, 2*n )
    {
        cnt += a[i].f != a[i-1].f;
        s[a[i].id] = cnt;
    }
}

void solve()
{
    compress();
    fill( idx, idx+2*n+1, 1e9 );
    ford( i, n, 0 )
        idx[s[i]] = i;
    foru( i, 1, 2*n )
        idx[i] = min( idx[i], idx[i-1] );
    int res = -1;
    foru( i, 1, n )
        res = max( res, i-idx[s[i+n]] );
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
