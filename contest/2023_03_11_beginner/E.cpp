#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }

    return res;
}

int main()
{
    ll a, x, m;
    cin >> a >> x >> m;

    ll ans = 0;

    ll cnt = 0;

    ll num = sqrt(x);
    // cout << num << endl;

    ll sum = 0;
    for (int i = 0; i < num; i++) {
        sum += modpow(a, i, m);
        sum %= m;
        cnt++;
    }

    ans = sum;

    for (int i = 1; (i+1)*num-1 < x; i++) {
        // cout << i * num << endl;
        ans = ans + modpow(a, i*num, m) * sum;
        ans %= m;
        cnt += num;
    }

    // cout << cnt << endl;

    for (; cnt < x; cnt++) {
        ans += modpow(a, cnt, m);
        ans %= m;
    }

    cout << ans << endl;

    return 0;
}