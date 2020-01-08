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
#define id second
#define haid "1."

using namespace std;

const int N = 1e5+1;

int n,k;
int bit[N];
pair < int, int > a[N];
int b[N];

void enter()
{
    cin >> n >> k;
    int s = 0;
    foru( i, 1, n )
    {
        int x;
        cin >> x;
        s += x >= k;
        a[i].f = 2*s - i;
        a[i].id = i;
    }
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

void solve()
{
    sort( a, a+n+1 );
    int cnt = 1;
    b[a[0].id] = cnt;
    foru( i, 1, n )
    {
        cnt += a[i].f != a[i-1].f;
        b[a[i].id] = cnt;
    }
    long long res = 0;
    foru( i, 0, n )
    {
        res += get( b[i] );
        modify( b[i] );
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
