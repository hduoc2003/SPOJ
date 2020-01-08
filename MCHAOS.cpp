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

typedef long long ll;

const int base = 31;
const int S = 1e5+1;

struct triple
{
    string fw,rev;
    int id;
};

int n;
int rev[S];
int bit[S];
triple a[S];

void enter()
{
    cin >> n;
    foru( i, 1, n )
    {
        cin >> a[i].fw;
        a[i].rev = string( a[i].fw.rbegin(), a[i].fw.rend() );
    }
}

int Get( int i )
{
    int res = 0;
    for( ; i; i &= i-1 )
        res += bit[i];
    return res;
}

void update( int i )
{
    for( ; i <= n; i += i & -i )
        bit[i]++;
}

void solve()
{
    sort( a+1, a+n+1, [&]( const triple& a, const triple& b )
    {
        return a.fw < b.fw;
    });
    foru( i, 1, n )
        a[i].id = i;
    sort( a+1, a+n+1, [&]( const triple& a, const triple& b )
    {
        return a.rev > b.rev;
    });
    foru( i, 1, n )
        rev[a[i].id] = i;
    long long res = 0;
    foru( i, 1, n )
    {
        res += Get( rev[i] - 1 );
        update( rev[i] );
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
