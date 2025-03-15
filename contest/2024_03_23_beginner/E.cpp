#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int h, w, m;
    cin >> h >> w >> m;

    vector<int> t(m), a(m), x(m);

    for (int i = 0; i < m; i++) {
        cin >> t[i] >> a[i] >> x[i];
    }

    int ri = h, rj = w;
    map<int, ll> cnt;
    vector<bool> usedh(h), usedw(w);
    for (int i = m-1; i >= 0; i--) {
        a[i]--;
        if (t[i] == 1) {
            if (usedh[a[i]]) continue;
            usedh[a[i]] = true;
            cnt[x[i]] += rj;
            ri--;
        } else {
            if (usedw[a[i]]) continue;
            usedw[a[i]] = true;
            cnt[x[i]] += ri;
            rj--;
        }
    }

    cnt[0] += (ll)ri*rj;

    vector<pair<int, ll>> ans;

    for (auto p : cnt) {
        if (p.second != 0) ans.emplace_back(p);
    }

    cout << ans.size() << endl;
    for (auto [c, x] : ans) {
        cout << c << " " << x << endl;
    }

    return 0;    
}