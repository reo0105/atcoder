#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int h, w, m;
    cin >> h >> w >> m;

    vector<ll> cnt(200005, 0);

    cnt[0] = (ll)h*w;

    vector<int> t(m), a(m), x(m);
    for (int i = 0; i < m; i++) cin >> t[i] >> a[i] >> x[i];

    int rh = h, rw = w;
    set<int> st_h, st_w;
    for (int i = m-1; i >= 0; i--) {
        int ti = t[i];
        int ai = a[i];
        int xi = x[i];

        if (ti == 1) {
            if (!st_h.count(ai)) {
                cnt[xi] += rw;
                cnt[0] -= rw;
                rh--;
                st_h.insert(ai);
            } 
        } else {
            if (!st_w.count(ai)) {
                cnt[xi] += rh;
                cnt[0] -= rh;
                rw--;
                st_w.insert(ai);
            }
        }
    }

    int k = 0;
    for (int i = 0; i < 200005; i++) {
        if (cnt[i] != 0) k++;
    }

    cout << k << endl;
    for (int i = 0; i < 200005; i++) {
        if (cnt[i] != 0) {
            cout << i << " " << cnt[i] << endl;
        }
    }

    return 0;
}