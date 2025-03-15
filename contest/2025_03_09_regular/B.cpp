#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> p(n);
    vector<ll> pos(n+1);
    fenwick_tree<int> tree(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i+1;
    }

    vector<ll> cnt(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        tree.add(p[i], 1);
        cnt[p[i]] = tree.sum(0, p[i]);
    }

    fenwick_tree<int> invtree(n+1);
    vector<ll> invcnt(n+1, 0);
    for (int i = 0; i < n; i++) {
        invcnt[p[i]] = invtree.sum(p[i], n+1);
        invtree.add(p[i], 1);
    }

    // for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << invcnt[i] << " ";
    // cout << endl;

    ll ans = 0;
    int c = 0;
    for (int i = n; i >= 1; i--) {
        if (cnt[i] == 0) continue;
        pos[i] -= invcnt[i];
        ll t = pos[i] + cnt[i] - 1;
        ans += t * (t+1) / 2;
        ans -= pos[i] * (pos[i] - 1) / 2; 
        c++;

        // cout << pos[i] << " " << t << " " << ans << endl;
    }

    cout << ans << endl;
}