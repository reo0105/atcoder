#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18+5

int main()
{
    ll n, m;

    cin >> n >> m;

    ll ans = INF;
    for (ll a = 1; a <= n; a++) {
        ll b = (m + a - 1) / a;

        if (b <= n) ans = min(ans, a*b);
        if (a > b) break;
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
} 