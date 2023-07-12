#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

vector<vector<int>> p(300005);
vector<int> xy(300005, -1);
vector<bool> done(300005, false);
int ans = 0;

void dfs(int from, int cnt)
{
    done.at(from) = true;
    cnt = max(cnt, xy.at(from));
    if (cnt > 0) {
        ans++;
        cnt--;
    }

    for (int u : p.at(from)) {
        dfs(u, cnt);
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        int t;
        cin >> t;
        p.at(t).push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        y++;
        if (xy.at(x) < y) {
            xy.at(x) = y;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!done.at(i)){
            dfs(1, xy.at(i));
        }
    }

    cout << ans << endl;
}