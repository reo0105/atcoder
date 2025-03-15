#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll t = lcm(n, m);

    ll l = t / n + t / m - 2;

    ll time = k / l;

    ll rem = k - l * time;

    ll ans0 = t * time;
    ll ans1 = t * time;

    if (rem == 0) {
        ans0 -= min(n, m);
        ans1 -= min(n, m);
    }

    for (int i = 0; i < rem; i++) {
        if (ans0 + n < ans1 + m) {
            ans0 += n;
        } else {
            ans1 += m;
        }
    }

    cout << max(ans0, ans1) << endl;


    return 0;
}