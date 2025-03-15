#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    using BS = bitset<2000>;
    vector<BS> d(n);

    for (int k = 0; k < m; k++) {
        map<int, vector<int>> is;
        for (int i = 0; i < n; i++) is[a[i][k]].push_back(i);

        BS x;
        for (auto p : is) {
            for (int i : p.second) x[i] = 1;
            for (int i : p.second) d[i] ^= x;
            for (int i : p.second) x[i] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ans += d[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}