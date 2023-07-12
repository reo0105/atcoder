#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;
typedef pair<int, int> pi;
typedef long long ll;
#define INF 1e18

struct edge {
    int u;
    int v;
    int c;

    // edge(int u, int v, int c) : u{u}, v{v}, c{c} {}
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<edge> G(200005);
    for (int i = 1; i <= m; i++) {
        edge tmp;
        cin >> tmp.u >> tmp.v >> tmp.c;
        G.at(i) = tmp;
    }

    vector<ll> dist(200005, INF);
    dist.at(1) = 0;

    for (int i = 0; i < k; i++) {
        int e;
        cin >> e;
        int u = G.at(e).u;
        int v = G.at(e).v;
        int c = G.at(e).c;

        dist.at(v) = min(dist.at(v), dist.at(u) + c);
    }

    if (dist.at(n) == INF) cout << -1 << endl;
    else cout << dist.at(n) << endl;

    return 0;
}