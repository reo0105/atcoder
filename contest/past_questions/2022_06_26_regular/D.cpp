#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<int> a(200005), b(200005);
vector<vector<p>> G(200005);
vector<int> done(200005, -1);
vector<bool> e(200005, false);
string ans = "";

void dfs(int from, int cnt, int par = -1)
{
    done.at(from) = cnt;

    for (auto x : G.at(from)) {
        int u = x.first;
        int num = x.second;
        if (e.at(num)) continue;

        e.at(num) = true; //通った辺にしるしをつける。
        if (a.at(num) == u) ans.at(num) = '1';

        // if (u == par) {
        //     continue;
        // }
        // if (done.at(u) == cnt) {
        //     // if (a.at(num) == u) 
        //     ans.at(num) = '1';
        //     return;
        // } else if (done.at(u) != -1) {
        //     // if (a.at(num) == u) ans.at(num) = '1';
        //     continue;
        // }
        // cout << u << " " << cnt << " " << from << endl;
        // if (a.at(num) == u) ans.at(num) = '1';

        if (done.at(u) == -1) dfs(u, cnt, from);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a.at(i);
    for (int i = 0; i < m; i++) cin >> b.at(i);


    for (int i = 0; i < m; i++) {
        G.at(a.at(i)).push_back(make_pair(b.at(i), i));
        G.at(b.at(i)).push_back(make_pair(a.at(i), i));
    }

    int cnt = 1;
    for (int i = 0; i < m; i++) ans.push_back('0');
    for (int i = 1; i <= n; i++) {
        if (done.at(i) == -1) {
            dfs(i, cnt);
            cnt++;
        }
    }

    cout << ans << endl;

    return 0;
}