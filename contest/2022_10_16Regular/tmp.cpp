#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<set<int>> inc(1005);
vector<int> done(1005, -1);
vector<vector<int>> G(1005);
vector<int> a(1005);
vector<int> num(1005, 0);

void dfs(int from, int par, int i)
{
    done.at(from) = i;

    for (int v : G.at(from)) {
        if (par == v) continue;

        dfs(v, from, i);
        for (int chi : inc.at(v)) inc.at(from).insert(chi);
        num.at(from) += num.at(v);
    }

    if (a.at(from) != -1) inc.at(from).insert(a.at(from));
    else num.at(from)++;
}


int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> p(1005);

        for (int j = 2; j <= n; j++) {
            int p;
            cin >> p;
            G.at(p).push_back(j);
        }
        for (int j = 1; j <= n; j++) cin >> a.at(j);

        dfs(1, -1, i);

        // for (int j = 1; j <= n; j++) {
        //     for (int s : inc.at(j)) cout << s << " ";
        //     cout << endl;
        // }

        int ok = 0;
        for (int j = 1; j <= n; j++) {
            if (inc.at(j).count(k)) continue;

            int cnt = 0;
            for (int l = 0; l < k; l++) {
                if (!inc.at(j).count(l)) cnt++;
            }
            // cout << j << " " << cnt << " " << num.at(j) << endl;;
            if (num.at(j) <= 1 && cnt == 0) { ok = 1; break;}
            if (cnt == 1 && num.at(j) == 1) { ok = 1; break; }
        }

        // for (int j = 1; j <= n; j++) {
        //     cout << num.at(j) << endl;
        // }


        if (ok) cout << "Alice" << endl;
        else cout << "Bob" << endl;


        for (int j = 1; j <= n; j++) G.at(j).clear();
        for (int j = 1; j <= n; j++) inc.at(j).clear();
        for (int j = 1; j <= n; j++) num.at(j) = 0;
    }

    return 0;
}