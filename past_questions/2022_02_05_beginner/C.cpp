#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    ll cnt = 1;
    int d;

    for (d = 0; d < n; d++) {
        if (n / cnt == 0) break;
        cnt *= 10;
    }

    // cout << d << endl;

    cnt = 9;
    ll t = 1;
    for (int i = 0; i < d-1; i++) {
        ans += (cnt+1) * cnt / 2;
        ans %= MOD;
        cnt *= 10;
        cnt %= MOD;
        t *= 10;
    }

    // cout << ans << " " << t << endl;

    n -= t;
    n++;
    // cout << n << endl;
    n %= MOD;

    ans += (n+1) * n / 2;
    ans %= MOD;

    cout << ans << endl;

    return 0;
}