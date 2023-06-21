#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<int>> G(200005);
vector<int> num(200005, -1);
int cnt = 1;

void dfs(int from)
{
    num.at(from) = cnt;

    for (int v : G.at(from)) {
        if (num.at(v) == -1) {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (num.at(i) == -1) {
            dfs(i);
            cnt++;
        }
    }


    int k;
    set<pi> s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x = num.at(x);
        y = num.at(y);
        if (x > y) swap(x, y);
        s.insert(make_pair(x, y));
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int pi, qi;
        cin >> pi >> qi;
        pi = num.at(pi);
        qi = num.at(qi);
        if (pi > qi) swap(pi, qi);

        if (s.count(make_pair(pi, qi))) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}