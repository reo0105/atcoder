#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

struct edge {
    edge(int v, int c) : to(v), cost(c){}
    int to;
    int cost;
    bool operator< (struct edge& e) {
        return cost < e.cost;
    }
};

vector<int> d(300005);
vector<vector<edge>> G(300005);
vector<vector<ll>> dp(300005, vector<ll>(2, 0));

void dfs(int u, int p)
{
    vector<ll> vec;
    for (auto e : G.at(u)) {
        int v = e.to;
        int w = e.cost;
        if (v == p) continue;
        dfs(v, u);

        vec.push_back(dp.at(v).at(0) + w - dp.at(v).at(1));
        dp.at(u).at(0) += dp.at(v).at(1);
        dp.at(u).at(1) += dp.at(v).at(1);
    }

    // cout << u << " " << dp.at(u).at(1) << endl;

    sort(vec.rbegin(), vec.rend());

    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec.at(i) <= 0) break;
        if (i < d.at(u) - 1) dp.at(u).at(0) += vec.at(i);
        if (i < d.at(u)) dp.at(u).at(1) += vec.at(i);
    }

    if (d.at(u) == 0) dp.at(u).at(0) = -INF; 
}


int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d.at(i);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.at(u).push_back(edge(v, w));
        G.at(v).push_back(edge(u, w));
    }

    dfs(1, -1);
    cout << dp.at(1).at(1) << endl;

    return 0;
}