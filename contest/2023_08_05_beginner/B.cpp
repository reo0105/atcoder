#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> to(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) if (!(int)to[i].size()) cnt++;

    if (cnt >= 2) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if ((int)to[i].size() == 0) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}