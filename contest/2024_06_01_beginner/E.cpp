#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    const int m = 1e6;

    vector<int> cnt(m+5, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<int> s(m+5);
    for (int i = 0; i <= m; i++) {
        s[i+1] = s[i] + cnt[i];
    }

    auto sum = [&](int l, int r) {
        r = min(m+1, r);
        return s[r]-s[l];
    };

    ll ans = 0;
    
    for (int i = 1; i <= m; i++) {
        ll now = 0;
        for (int j = 1; i*j <= m; j++) {
            ll l = i * j, r = i * (j + 1);
            now += (ll)sum(l, r) * j;
        }
        now -= cnt[i];
        ans += now*cnt[i];
        ans += (ll)cnt[i]*(cnt[i]-1)/2;
    }

    cout << ans << endl;

    return 0;
}