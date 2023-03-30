#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define MOD 998244353

int main()
{
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;

    vector<p> G;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.push_back(make_pair(u, v));
    }

    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(2005, vector<ll>(2005, 0)));

    dp.at(0).at(0).at(s) = 1;
    for (int i = 1; i <= k; i++) {
        for (p next : G) {
            int u = next.first;
            int v = next.second;
            for (int j = 0; j < 2; j++) {
                dp.at((v == x) ^ j).at(i).at(v) += dp.at(j).at(i-1).at(u);
                dp.at((u == x) ^ j).at(i).at(u) += dp.at(j).at(i-1).at(v);
                dp.at((v == x) ^ j).at(i).at(v) %= MOD;
                dp.at((u == x) ^ j).at(i).at(u) %= MOD;
            }
        }
    }

    cout << dp.at(0).at(k).at(t) << endl;

    return 0;
}