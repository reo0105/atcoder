#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

int main()
{
    ll a, b ,c, d, e, f, ans;
    cin >> a >> b >> c >> d >> e >> f;

    a %= MOD;
    b %= MOD;
    c %= MOD;
    d %= MOD;
    e %= MOD;
    f %= MOD;

    a = (a * b) % MOD;
    a = (a * c) % MOD;
    d = (d * e) % MOD;
    d = (d * f) % MOD;

    ans = ((a - d) < 0) ? a + MOD - d : a - d;

    cout << ans << endl;
    return 0;
}