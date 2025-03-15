#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, d, k, now = 0;
        cin >> n >> d >> k;
        ll lc = lcm(n, d);
        ll loop = lc / d;
        ll cnt = (k-1) / loop;
        ll re = k - cnt*loop;
        // cout << lc << " " << loop << " " << cnt << " " << re << endl;
        cout << (d * (re-1) + cnt) % n << endl;
    }

    return 0;
}