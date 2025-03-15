#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> G(200002);
vector<int> color(200002, -1);

bool dfs(int from, int now_color, vector<ll> &num)
{
    color.at(from) = now_color;
    num.at(now_color) += 1;

    for (int next : G.at(from)) {
        if (color.at(next) != -1) {
            if (color.at(next) == now_color) return false;
            else continue;
        } else {
            int nc = (now_color) ? 0 : 1;
            if (!dfs(next, nc, num)) return false;
        }
    }

    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    ll ans = n * (n-1) / 2 - m;

    for (int i = 1; i <= n; i++) {
        if (color.at(i) == -1) {
            vector<ll> num(2, 0);
            if (!dfs(i, 0, num)) {
                cout << 0 << endl;
                return 0;
            }

            ans -= num.at(0) * (num.at(0)-1) / 2;
            ans -= num.at(1) * (num.at(1)-1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}