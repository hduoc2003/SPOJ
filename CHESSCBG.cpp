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

struct data
{
    int u[4];
};

data s,f;
int d[16][16][16][16];

void enter()
{
    string a;
    foru( i, 0, 7 )
    {
        cin >> a;
        ford( j, 3, 0 )
            if ( i <= 3 )
                s.u[i] = s.u[i] << 1 | ( a[j] - 48 );
            else
                f.u[i-4] = f.u[i-4] << 1 | ( a[j] - 48 );
    }
}

#define _(v) v.u[0]][v.u[1]][v.u[2]][v.u[3]

void solve()
{
    queue < data > q;
    auto push = [&]( data& u, data& v )
    {
        if ( !d[_(v)] )
            d[_(v)] = d[_(u)]+1, q.ep( v );
    };
    q.ep( s );
    while ( q.size() )
    {
        s = q.front();
        if ( s.u[0] == f.u[0] && s.u[1] == f.u[1] && s.u[2] == f.u[2] && s.u[3] == f.u[3] )
        {
            cout << d[_(f)];
            return;
        }
        q.pop();
        foru( i, 0, 3 )
        {
            foru( j, 0, 3 )
                if ( s.u[i] & ( 1 << j ) )
                {
                    int t = 1 << j;
                    if ( i > 0 && !( s.u[i-1] & t ) )
                    {
                        data v = { -1, -1, -1, -1 };
                        v.u[i-1] = s.u[i-1] | t, v.u[i] = s.u[i] ^ t;
                        foru( k, 0, 3 )
                            if ( v.u[k] == -1 )
                                v.u[k] = s.u[k];
                        push( s, v );
                    }
                    if ( j > 0 && !( s.u[i] & ( 1 << j-1 ) ) )
                    {
                        data v = s;
                        v.u[i] ^= 3 << j-1;
                        push( s, v );
                    }
                    if ( i < 4 && !( s.u[i+1] & t ) )
                    {
                        data v = { -1, -1, -1, -1 };
                        v.u[i] = s.u[i] ^ t, v.u[i+1] = s.u[i+1] | t;
                        foru( k, 0, 3 )
                            if ( v.u[k] == -1 )
                                v.u[k] = s.u[k];
                        push( s, v );
                    }
                    if ( j < 3 && !( s.u[i] & ( 1 << j+1 ) ) )
                    {
                        data v = s;
                        v.u[i] ^= 3 << j;
                        push( s, v );
                    }
                }
        }
    }
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
