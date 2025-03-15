#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct D {
    int n, w;
    vector<int> cnt;
    D() {}
    D(vector<int> x) {
        n = (int)x.size();
        sort(x.begin(), x.end());
        w = x.back() - x[0];
        cnt.assign(n, 0);
        for (int i = 0; i < n-1; i++) {
            int cost = min(i+1, n-i-1);
            cnt[cost] += x[i+1]-x[i];
        }
    }

    ll get (int r) {
        ll res = 0;
        int m = w-r;
        for (int i = 0; i < n; i++) {
            int x = min(m, cnt[i]);
            m -= x;
            res += (ll)x*i;
        }
        return res;
    }
};

int main() {
    
    int n;
    ll k;
    cin >> n >> k;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    D dx(x), dy(y);

    int ac = 1e9, wa = -1;

    while (ac-wa > 1) {
        int wj = (ac+wa) / 2;

        ll num = dx.get(wj) + dy.get(wj);
        if (num <= k) ac = wj;
        else wa = wj;
    }

    cout << ac << endl;
    return 0;
}