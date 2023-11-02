#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n+1, 0), b(m, 0);
    vector<ll> sumb(m+1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    // for (int i = 1; i <= n; i++) a[i] += a[i-1];
    for (int i = 1; i <= m; i++) sumb[i] = b[i-1] + sumb[i-1];

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll lim = p - a[i];

        int id = lower_bound(b.begin(), b.end(), lim) - b.begin();

        // cout << id << " " << sumb[id] << " "; 
        // cout << *lower_bound(b.begin(), b.end(), lim) << " ";
        if (id != 0) ans += (ll)a[i] *id + sumb[id] + (ll)p * (m-id);
        else ans += (ll)p * m;
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}