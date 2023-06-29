#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#include <atcoder/fenwicktree>
using namespace atcoder;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a.at(i).at(j);
        }
    }

    vector<pi> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b.emplace_back(a.at(i).at(j), i);
        }
    }

    sort(b.begin(), b.end());

    ll ans = (ll)((m+1) * m / 2) * (n * (n-1) / 2);
    fenwick_tree<int> fw(n+1);

    for (auto [_, x] : b) {
        fw.add(x, 1);
        ans += fw.sum(x+1, n);
    }

    cout << ans << endl;

    return 0;
}