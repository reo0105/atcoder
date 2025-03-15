#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2e18
/*
dfsして左右で分けてO(1）でいけそう？

無理だ

距離がKのやつの探索に最悪O(n）かかる。

各頂点についてありうる最大の距離を求めとく？
→それ以下であれば可能になる。
その差分からなんとかできるか？

*/
vector<vector<int>> G(200005);
int depth = 0;
int maxi = -1, node;
vector<vector<int>> par_a(200005, vector<int>(20, -1));
vector<vector<int>> par_b(200005, vector<int>(20, -1));

int dfs1(int from, int pre)
{
    depth++;
    for (int v : G.at(from)) {
        if (v == pre) continue;
        if (maxi < depth) {
            maxi = depth;
            node = v;
        }

        dfs1(v, from);
    }

    depth--;

    return node;
}

void dfs2(int from, int pre, int is_a)
{
    for (int v : G.at(from)) {
        if (v == pre) continue;

        if (is_a) par_a.at(v).at(0) = from;
        else par_b.at(v).at(0) = from;

        dfs2(v, from, is_a);
    }
}

int main()
{
    int n;

    // ios::sync_with_stdio(false);
	// cin.tie(0);

    // cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    int a = dfs1(1, -1);
    maxi = -1;
    int b = dfs1(a, -1);

    dfs2(a, -1, 1);
    dfs2(b, -1, 0);

    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= n; i++) {
            int ta = par_a.at(i).at(j-1);
            if (ta != -1) par_a.at(i).at(j) = par_a.at(ta).at(j-1);
            else par_a.at(i).at(j) = -1;
        }
    }

    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= n; i++) {
            int tb = par_b.at(i).at(j-1);
            if (tb != -1) par_b.at(i).at(j) = par_b.at(tb).at(j-1);
            else par_b.at(i).at(j) = -1;
        }
    }

    int q;
    // cin >> q;
    scanf("%d", &q);

    // cout << a << " " << b << endl;
    // for (int i = 1; i <= n; i++) cout << par_a.at(i).at(1) << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << par_a.at(i).at(2) << " ";
    // cout << endl;

    for (int i = 0; i < q; i++) {
        int u, k;
        // cin >> u >> k;
        scanf("%d %d", &u, &k);

        int cnt = 0, ans = u;
        while ((k>>cnt) > 0) {
            if ((k>>cnt) & 1) {
                if (ans != -1) ans = par_a.at(ans).at(cnt);
            }
            cnt++;
        }

        if (ans != -1) {
            // cout << ans << endl;
            printf("%d\n", ans);
            continue;
        }

        cnt = 0, ans = u;
        while ((k>>cnt) > 0) {
            if ((k>>cnt) & 1) {
                if (ans != -1) ans = par_b.at(ans).at(cnt);
            }
            cnt++;
        }

        // cout << ans << endl;
        printf("%d\n", ans);
    }

    return 0;
}