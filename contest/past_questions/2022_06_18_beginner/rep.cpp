#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    int to;
    int cost;
};

vector<edge> G(200005);
vector<int> seen(200005, 0);
stack<int> stk;
int loop = false;

int dfs(int from, int cnt, int &end)
{
    int c = 0;
    seen.at(from) = cnt;
    stk.push(from);

    int n = G.at(from).to;
    if (seen.at(n) != 0 && seen.at(n) != cnt) return 0;
    if (seen.at(n) == 0) {
        c = dfs(n, cnt, end);
        int b = stk.top();
        stk.pop();
        if (loop) {
            if (end == b) loop = false;
            return min(c, G.at(from).cost);
        } else return c;
    } else if (seen.at(n) == cnt) {
        end = n;
        loop = true;
        stk.pop();
        return G.at(from).cost;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        G.at(i).to = x;
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        G.at(i).cost = c;
    }

    ll ans = 0, t = 0;
    int cnt = 1, end = -1;
    for (int i = 1; i <= n; i++) {
        if (seen.at(i) == 0) {
            ans += dfs(i, cnt, end);
            cnt++;
            end = -1;
        }
    }

    cout << ans << endl;
}