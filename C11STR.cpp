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

const int S = 2e5+1;

string a,b;
int lps[S];

void enter()
{
    cin >> a >> b;
}

void solve()
{
    int m = b.size();
    b.push_back( '*' );
    b += a;
    int n = b.size() - 1;
    foru( i, 1, n )
    {
        int tmp = lps[i-1];
        while ( tmp && b[i] != b[tmp] )
            tmp = lps[tmp-1];
        if ( b[i] == b[tmp] )
            lps[i] = ++tmp;
    }
    cout << a;
    while ( lps[n] < m )
        cout << b[lps[n]++];
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
