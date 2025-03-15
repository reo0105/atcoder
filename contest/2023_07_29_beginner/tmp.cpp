#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a, b, c;
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 0) a.push_back(x);
        if (t == 1) b.push_back(x);
        if (t == 2) c.push_back(x);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    vector<ll> sum_a((int)a.size()+1);
    vector<ll> sum_b((int)b.size()+1);
    vector<ll> sum_c((int)c.size()+1);

    for (int i = 0; i < (int)a.size(); i++) sum_a[i+1] = sum_a[i] + a[i];
    for (int i = 0; i < (int)b.size(); i++) sum_b[i+1] = sum_b[i] + b[i];
    for (int i = 0; i < (int)c.size(); i++) sum_c[i+1] = sum_c[i] + c[i];

    for (int i = (int)a.size(); i < m; i++) sum_a.push_back(sum_a[(int)a.size()]);
    for (int i = (int)b.size(); i < m; i++) sum_b.push_back(sum_b[(int)b.size()]);
    for (int i = (int)c.size(); i < m; i++) sum_c.push_back(sum_c[(int)c.size()]);

    ll ans = 0;
    for (int bi = 0; bi <= m; bi++) {
        int ci = lower_bound(sum_c.begin(), sum_c.end(), bi) - sum_c.begin();
        if (bi > sum_c[ci]) continue;
        if (ci + bi > m) continue;
        ll t = sum_b[bi];
        int ai = m - ci - bi;
        t += sum_a[ai];
        ans = max(ans, t);
        // cout << t << " " << ci <<  " " << sum_c[ci] << " " << sum_b[bi] << " " << ai << " " << sum_a[ai] << endl;
    }

    cout << ans << endl;

    return 0;
}