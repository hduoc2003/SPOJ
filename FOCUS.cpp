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
#define haid "1."

using namespace std;

const int N = 2e5+1;

struct data
{
    int val,id;
    bool type;
    data( const int& a, const int& b, const bool& c ): val( a )
    {
        id = b, type = c;
    }
    bool operator < ( const data& a ) const
    {
        return val < a.val;
    }
};

int n;
char act[N];
int x[N],y[N],k[N];
int ori[N];
int bit[N];
vector < data > a;

void enter()
{
    cin >> n;
    foru( i, 1, n )
    {
        cin >> act[i];
        if ( act[i] == '?' )
        {
            cin >> k[i] >> x[i] >> y[i];
            a.ep( y[i], i, 2 );
        }
        else
            cin >> x[i];
        a.ep( x[i], i, 0 );
    }
}

void compress()
{
    sort( a.begin(), a.end() );
    int cnt = 1, as = a.size();
    a[0].type ? y[a[0].id] = 1 : x[a[0].id] = 1;
    for( int i = 1; i < as; i++ )
    {
        cnt += a[i].val != a[i-1].val;
        a[i].type ? y[a[i].id] = cnt : x[a[i].id] = cnt;
        ori[cnt] = a[i].val;
    }
}

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

void solve()
{
    compress();
    foru( i, 1, n )
        if ( act[i] == '-' )
            modify( x[i], -1 );
        else
            if ( act[i] == '+' )
                modify( x[i], 1 );
            else
            {
                int res = 0, tmp = get( x[i]-1 );
                while ( x[i] <= y[i] )
                {
                    int m = ( x[i] + y[i] ) >> 1;
                    if ( get( m ) - tmp >= k[i] )
                        res = m, y[i] = --m;
                    else
                        x[i] = ++m;
                }
                cout << ori[res] << '\n';
            }
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
