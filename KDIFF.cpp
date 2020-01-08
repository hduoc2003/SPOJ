#include <iostream>
#include <fstream>
#include <queue>

#define foru( i, a, b ) for( int i = a; i <= b; i++ )
#define fr freopen
#define haid "1."

using namespace std;

const int S = 3e5+1;
int n,k;
int a[S],f[S];
deque < int > qmin,qmax;

int main()
{
    ios_base :: sync_with_stdio( false ); cin.tie( 0 );
    fr( haid"INP", "r", stdin );
    cin>>n>>k;
    int j = 1;
    foru( i, 1, n )
    {
        cin>>a[i];
        while ( qmin.size() && qmin.back() > a[i] )
            qmin.pop_back();
        while ( qmax.size() && qmax.back() < a[i] )
            qmax.pop_back();
        qmin.push_back( a[i] ), qmax.push_back( a[i] );
        while ( qmax.front() - qmin.front() > k )
        {
            if ( qmax.front() == a[j] )
                qmax.pop_front();
            if ( qmin.front() == a[j] )
                qmin.pop_front();
            j++;
        }
        f[i] = i - j + 1;
    }
    int res = 0;
    foru( i, 1, n )
    {
        res = max( res, f[i] + f[i-f[i]] );
        f[i] = max( f[i], f[i-1] );
    }
    cout<<res;
}
