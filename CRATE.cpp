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
#define haid "1."

using namespace std;

struct data
{
    int f,s,id;
    bool operator < ( const data& a ) const
    {
        return f < a.f || ( f == a.f && s < a.s );
    }
};

const int N = 3e5+1, A = 1e5+1;

int n;
data a[N];
int bit[A];
int res[N];

void enter()
{
    cin >> n;
    foru( i, 1, n )
    {
        cin >> a[i].f >> a[i].s;
        a[i].id = i;
    }
}

void modify( int i )
{
    for( ; i < A; i += i & -i )
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
    sort( a+1, a+n+1 );
    foru( i, 1, n )
    {
        res[a[i].id] = ( a[i].f == a[i-1].f && a[i].s == a[i-1].s ) ? res[a[i-1].id] : get( a[i].s );
        modify( a[i].s );
    }
    foru( i, 1, n )
        cout << res[i] << '\n';
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
