#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_map>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define ford( i, a, b ) for( int i = a; i >= b; i-- )
#define fr freopen
#define ps push_back
#define haid "1."

using namespace std;

const int S = 1002;
int n,m;
int h[S][S];
int l[S];

void enter()
{
    cin>>m>>n;
    foru( i, 1, m )
        foru( j, 1, n )
        {
            bool x;
            cin>>x;
            h[i][j] = x ? h[i-1][j] + 1 : 0;
        }
}

void solve()
{
    int res = 0;
    foru( i, 1, m )
    {
        deque < int > q;
        q.ps( 0 );
        h[i][0] = h[i][n+1] = -1;
        foru( j, 1, n )
        {
            while ( h[i][q.back()] >= h[i][j] )
                q.pop_back();
            l[j] = q.back() + 1;
            q.ps( j );
        }
        q.clear(), q.ps( n+1 );
        ford( j, n, 1 )
        {
            while ( h[i][q.back()] >= h[i][j] )
                q.pop_back();
            res = max( res, h[i][j] * ( q.back() - l[j] ) );
            q.ps( j );
        }
    }
    //cout<<res;
    foru( i, 1, m )
    {
        foru( j, 1, n )
            cout<<h[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    fr( haid"INP", "r", stdin );
    enter();
    solve();
}
