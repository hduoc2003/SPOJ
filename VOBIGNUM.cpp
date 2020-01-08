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

typedef long long ll;

const int S = 1001;
const int NMOD = 3;
const int mod[] = { (int)1e9+2277, (int)1e9+5277, (int)1e9+8277, (int)1e9+9277 };

int n,q;
ll h[NMOD+1][S];

void enter()
{
    cin >> n >> q;
    string s;
    for( int l = 0; l < n; l++ )
    {
        cin >> s;
        for( int i = 0; i <= NMOD; i++ )
        {
            ll x = 0;
            for( int j = ( s[0] == '-' ); j < s.size(); j++ )
            {
                x = x * 10 + s[j] - 48;
                x %= mod[i];
            }
            h[i][l] = s[0] == '-' ? -x : x;
        }
    }
}

void solve()
{
    while ( q-- )
    {
        int a,b,c,d;
        char x,y;
        cin >> a >> b >> x >> c >> d >> y;
        bool check = 1;
        foru( i, 0, NMOD )
        {
            ll a1 = h[i][a], b1 = h[i][b];
            //cout << a1 << " " << b1 << '\n';
            ll val1 = x == '-' ? a1 - b1 : ( x == '+' ? a1 + b1 : a1*b1 );
            a1 = h[i][c], b1 = h[i][d];
            ll val2 = y == '-' ? a1 - b1 : ( y == '+' ? a1 + b1 : a1*b1 );
            //cout << val1 << " " << val2 << '\n';
            if ( val1 != val2 )
            {
                check = 0;
                break;
            }
        }
        cout << ( check ? "YES\n" : "NO\n" );
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
