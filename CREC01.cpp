#include <iostream>
#include <fstream>
#include <queue>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )

using namespace std;

const int S = 1001;
int n,m;
int h[S],f[S];

void solve()
{
    cin>>m>>n;
    h[0] = -1;
    long long res = 0;
    foru( i, 1, m )
    {
        deque < int > q;
        q.push_back( 0 );
        foru( j, 1, n )
        {
            char x;
            cin>>x;
            h[j] = x - 48 ? ++h[j] : 0;
            while ( h[q.back()] >= h[j] )
                q.pop_back();
            res += f[j] = f[q.back()] + h[j] * ( j - q.back() );
            q.push_back( j );
        }
    }
    cout<<res;
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    freopen( "1.INP", "r", stdin );
    solve();
}
