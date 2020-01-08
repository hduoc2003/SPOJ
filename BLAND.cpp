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
#define ps push_back
#define haid "1."

using namespace std;

const int S = 301, inf = 2e9;

int n,m,d;
int h[S][S],k[S][S];
int dp[S][S];
int maxr[S],minr[S];

void enter()
{
    cin >> m >> n >> d;
    foru( i, 1, m )
        foru( j, 1, n )
            cin >> h[i][j];
}

int find_res( int m, int n, int h[][S] )
{
    foru( i, 1, m )
    {
        foru( j, 1, n )
            maxr[j] = -inf, minr[j] = inf;
        foru( j, i, m )
        {
            deque < int > qmax,qmin;
            int l = 1, ans = 0;
            foru( k, 1, n )
            {
                maxr[k] = max( maxr[k], h[j][k] );
                minr[k] = min( minr[k], h[j][k] );
                while ( qmax.size() && qmax.back() < maxr[k] )
                    qmax.pop_back();
                while ( qmin.size() && qmin.back() > minr[k] )
                    qmin.pop_back();
                qmax.push_back( maxr[k] ), qmin.push_back( minr[k] );
                while ( l <= k && qmax.front() - qmin.front() > d )
                {
                    if ( qmax.front() == maxr[l] )
                        qmax.pop_front();
                    if ( qmin.front() == minr[l] )
                        qmin.pop_front();
                    l++;
                }
                ans = max( ans, ( j-i+1 )*( k-l+1 ) );
            }
            dp[i][j] = ans;
        }
    }
    return [&]() mutable -> int
    {
        int res = 0;
        for( int i = 1; i < m; i++ )
        {
            int smax1 = 0, smax2 = 0;
            foru( x, 1, i )
                foru( y, x, i )
                    smax1 = max( smax1, dp[x][y] );
            foru( x, i+1, m )
                foru( y, x, m )
                    smax2 = max( smax2, dp[x][y] );
            res = max( res, smax1 + smax2 );
        }
        return res;
    }();
}

void solve()
{
    foru( j, 1, n )
        foru( i, 1, m )
            k[j][i] = h[i][j];
    cout << max( find_res( m, n, h ), find_res( n, m, k ) );
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
