#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a, m, l, r;

    cin >> a >> m >> l >> r;

    l-=a; r-=a;
    if (l < 0) {
        ll x = -l/m+1;
        l+=x*m; r+=x*m;
    }

    ll ans = 0;

    ans = r/m - (l-1)/m;

    cout << ans << endl; 

    return 0;
}