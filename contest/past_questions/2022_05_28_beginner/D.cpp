#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    ll ans = 0;
    cin >> n >> a >> b;

    ll lc = lcm(a, b);

    ans = n * (n + 1) / 2;
    ans -= a * (n / a) * (n / a + 1) / 2;
    ans -= b * (n / b) * (n / b + 1) / 2;
    ans += lc * (n / lc) * (n / lc + 1) / 2;

    cout << ans << endl;

    return 0;
}