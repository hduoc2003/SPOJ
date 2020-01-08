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

const int N = 3e4+1, Q = 2e5+1;

int n,q;
int a[N];
int last_pos[(int)1e6+1];
int bit[N];
int res[Q];
vector < pair < int, int > > qr[N];


void modify( int i, int delta )
{
    for( ; i <= n; i += i & -i )
        bit[i] += delta;
}

int get( int i )
{
    int res = 0;
    for( ; i; i &= i-1 )
        res += bit[i];
    return res;
}

void enter()
{
    cin >> n;
    foru( i, 1, n )
        cin >> a[i];
    cin >> q;
    foru( i, 1, q )
    {
        int l,r;
        cin >> l >> r;
        qr[r].ep( l, i );
    }
}

void solve()
{
    foru( i, 1, n )
    {
        modify( i, 1 );
        if ( last_pos[a[i]] )
            modify( last_pos[a[i]], -1 );
        last_pos[a[i]] = i;
        for( auto& p : qr[i] )
            res[p.second] = get( i ) - get( p.first - 1 );
    }
    foru( i, 1, q )
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
