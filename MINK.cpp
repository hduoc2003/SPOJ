#include <iostream>
#include <fstream>
#include <queue>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define fr freopen
#define haid "1."

using namespace std;

const int S = 17001, inf = 2e9+1;
int t,n,k;
int a[S];

void enter()
{
    cin>>n>>k;
    foru( i, 1, n )
        cin>>a[i];
}

void solve()
{
    deque < int > q;
    auto push = [&]( const int& x )
    {
        while ( q.size() && a[q.back()] > a[x] )
            q.pop_back();
        q.push_back( x );
    };
    for( int i = 1; i < k; i++ )
        push( i );
    foru( i, 1, n-k+1 )
    {
        push( i+k-1 );
        while ( q.front() < i )
            q.pop_front();
        cout<<a[q.front()]<<" ";
    }
    cout<<'\n';
}

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    fr( haid"INP", "r", stdin );
    cin>>t;
    while ( t-- )
    {
        enter();
        solve();
    }
}
