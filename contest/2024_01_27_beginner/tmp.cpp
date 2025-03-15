#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    stack<int> stk;

    vector<int> u(n), v(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        mp[v] = u;
    }

    int ok = 0;
    for (int i = 1; i <= n*2; i++) {
        if (mp.count(i)) {
            int top = stk.top();
            stk.pop();
            if (top != mp[i]) {
                ok = 1;
            }
        } else {
            stk.push(i);
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}