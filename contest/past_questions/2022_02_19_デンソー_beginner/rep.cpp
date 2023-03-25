#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

vector<int> x(100005);
vector<vector<int>> G(100005);
vector<vector<int>> dist(100005);


void dfs(int from, int pre)
{

    dist.at(from).push_back(x.at(from));

    for (int v : G.at(from)) {
        if (v == pre) continue;

        dfs(v, from);

        for (auto des : dist.at(v)) {
            dist.at(from).push_back(des);
        }
        sort(dist.at(from).rbegin(), dist.at(from).rend());
        dist.at(from).resize(20);
    }

    return;
}

int main()
{
    int n, q;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> x.at(i);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    dfs(1, -1);

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        cout << dist.at(v).at(k-1) << endl;
    }

    return 0;
}