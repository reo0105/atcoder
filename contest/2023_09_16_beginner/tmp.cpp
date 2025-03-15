#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<int> t(m), w(m), s(m);
    vector<ll> ans(n+2, 0);

    priority_queue<int, vector<int>, greater<int>> row;
    priority_queue<pii, vector<pii>, greater<pii>> wait;

    for (int i = 1; i <= n; i++) row.push(i);

    for (int i = 0; i < m; i++) {
        int t, w, s;
        cin >> t >> w >> s;

        while (wait.size()) {
            pii top = wait.top();
            if (top.first <= t) {
                row.push(top.second);
                wait.pop();
            } else {
                break;
            }
        }

        if (row.size()) {
            int first = row.top();
            row.pop();
            ans[first] += w;
            wait.push(make_pair(t+s, first));
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << endl;

    return 0;
}