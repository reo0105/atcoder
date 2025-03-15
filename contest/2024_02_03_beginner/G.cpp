#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segtree {
    int n;
    vector<vector<int>> a;
    vector<vector<ll>> sum;

    segtree(int mx) {
        n = 1;
        while (n < mx) n <<= 1;

        a.resize(2*n);
        sum.resize(2*n, vector<ll>(1, 0));
    }

    void set(int i, int x) {
        a[n+i] = {x};
        sum[n+i].push_back(x);
    }

    void init() {
        for (int i = n-1; i > 0; i--) {
            int l = i<<1, r = l+1;
            merge(a[l].begin(), a[l].end(),
                  a[r].begin(), a[r].end(),
                  back_inserter(a[i]));
            sum[i] = vector<ll>((int)a[i].size()+1);
            for (int j = 0; j < (int)a[i].size(); j++) {
                sum[i][j+1] = sum[i][j] + a[i][j];
            }
        }
    }

    ll get(int i, int x) {
        int j = upper_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
        return sum[i][j];
    }

    ll solve(int l, int r, int x) {
        l += n;
        r += n;
        ll res = 0;
        while (l < r) {
            if (l&1) res += get(l++, x);
            if (r&1) res += get(--r, x);
            l >>= 1; r >>= 1;
        }
        return res;
    }

};


int main()
{
    int n;
    cin >> n;

    segtree seg(n+1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        seg.set(i, a);
    }

    seg.init();

    int q;
    cin >> q;

    ll b = 0;
    for (int i = 0; i < q; i++) {
        ll l, r, x;
        cin >> l >> r >> x;

        l^=b;
        r^=b;
        x^=b;
        
        l--;
        b = seg.solve(l, r, x);
        cout << b << endl;
    }
    return 0;
}