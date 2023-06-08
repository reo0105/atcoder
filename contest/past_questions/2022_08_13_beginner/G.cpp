#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    int from;
    int to;
    ll cost;
    edge (int a, int b, ll c): from(a), to(b), cost(c) {}
};

int main()
{
    int n;
    map<string, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        int p;
        cin >> t >> p;
        mp[t] = p;
    }

    int n1 = 27*27;
    vector<edge> es;

    for (int v = 0; v < n1; v++) {
        for (int c = 0; c < 26; c++) {
            int u = v % 27*27+ c;
            ll co = 0;
            string s;
            s += 'a' + v/27;
            s += 'a' + v%27;
            s += 'a' + c;
            // if (s.at(1) > 'z') cout << s << " ";
            for (int i = 0; i < 3; i++) co += mp[s.substr(i)];
            es.emplace_back(v, u, -co);
        }
    }

    ll INF = 2e18;
    vector<ll> dist(n1, INF);
    dist.at(n1-1) = 0;
    for (int i = 0; i < n1; i++) {
        bool upd = false;
        for (auto [from, to, c] : es) {
            ll d = dist.at(from) + c;
            if (dist.at(to) <= d) continue;
            dist.at(to) = d;
            upd = true;
        }
        if (!upd) break;
        if (i == n1-1) {
            cout << "Infinity" << endl;
            return 0;
        }
    }

    ll ans = INF;
    for (int i = 0; i < n1; i++) {
        if (i%27 == 26) continue;
        ans = min(ans, dist.at(i));
    }

    cout << -ans << endl;
}