#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

set<int> seen;
vector<int> ans;
vector<vector<int>> G(200005);
int idx = 0;

void dfs(int from, int end)
{
    if (seen.count(from)) return;
    seen.insert(from);

    for (int v : G.at(from)) {
        dfs(v, end);
    }
    ans.push_back(from);
}

int main()
{
    int n, m;
    int l = 0, r = 0;
    vector<set<int>> s(200005);
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        // if (i == 0) { l = x; r = y; }
        // else if (l == y || y < l) l = x;
        // else if (r == x || x > r) r = y;

        if (s.at(x).count(y)) continue;
        else {
            // cout << x << " -> " << y << endl;
            G.at(x).push_back(y);
            s.at(x).insert(y);
        }
        // cout << l << " " << r << endl;
    }

    for (int i = 1; i <= n; i++ ) dfs(i, n);
    // for (int i = 0; i < (int)ans.size(); i++) cout << ans.at(i) << " ";

    bool ok = true;

    // if ((int)ans.size() == n) {
        for (int i = 0; i < n-1; i++) {
            int a = ans.at(i), b = ans.at(i+1);
            if (!s.at(b).count(a)) ok = false; 
        }
    // } else {
        // ok = false;
    // }

    vector<int> tans(200005);
    if ((int)ans.size() == n && ok) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            tans.at(ans.at(i)) = n-i;
        }
        for (int i = 1; i <= n; i++) {
            cout << tans.at(i) << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
     
    return 0;
}