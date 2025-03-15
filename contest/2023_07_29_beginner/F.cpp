#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main()
{
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
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<ll> sum_a(n+1, 0);
    for (int i = 0; i < (int)a.size(); i++) sum_a[i+1] = sum_a[i] + a[i];
    for (int i = (int)a.size(); i < n; i++) sum_a[i+1] = sum_a[i];

    int cnt = 0;
    vector<ll> sum_b(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (b.empty()) sum_b[i+1] = sum_b[i];
        else if (cnt == 0) {
            if (!c.empty()) {
                cnt += c.back();
                c.pop_back();
            }
            sum_b[i+1] = sum_b[i];
        } else {
            cnt--;
            sum_b[i+1] = sum_b[i] + b.back();
            b.pop_back();
        }
    }

    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, sum_a[i] + sum_b[m-i]);
    }

    cout << ans << endl;

    return 0;
}