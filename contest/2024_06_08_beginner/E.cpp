#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> used(n);
    vector<int> idx(n, -1);
    vector<int> cnt(n);
    vector<int> ord;

    for (int sv = 0; sv < n; sv++) {
        if (!used[sv]) {
            int v = sv;
            vector<int> vs;
            while (1) {
                if (used[v]) break;
                if (idx[v] != -1) {
                    vector<int> cyc(vs.begin()+idx[v], vs.end());
                    for (int u : cyc) {
                        cnt[u] = (int)cyc.size();
                    }
                    break;
                }
                idx[v] = (int)vs.size();
                vs.push_back(v);
                v = a[v];
            }

            for (int v : vs) used[v] = true;
            reverse(vs.begin(), vs.end());
            ord.insert(ord.end(), vs.begin(), vs.end());
        }

    }

    for (int v : ord) {
        if (cnt[v] != 0) continue;
        cnt[v] = cnt[a[v]] + 1;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) ans += cnt[i];

    cout << ans << endl;

    return 0;
}