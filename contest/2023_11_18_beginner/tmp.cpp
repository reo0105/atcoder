#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    queue<int> que;
    vector<bool> done(n, false);

    for (int i = 0; i <= n-m; i++) {
        int ok = 1;
        for (int j = 0; j < m; j++) {
            if (s[i+j] != t[j]) ok = 0;
        }

        if (ok) {
            que.push(i);
        }
    }


    while (que.size()) {
        int i = que.front();
        que.pop();

        if (done[i]) continue;
        if (i > n-m) continue;

        int ok = 1;
        for (int j = 0; j < m; j++) {
            if (!(s[i+j] == t[j] || s[i+j] == '#')) {
                ok = 0;
            }
        }

        if (ok) {
            done[i] = true;
            for (int j = 0; j < m; j++) {
                s[i+j] = '#';
            }

            for (int j = max(0, i-m+1); j <= i-1; j++) que.push(j);
            for (int j = i+1; j <= min(n, i+m-1); j++) que.push(j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') cnt++;
    }

    // cout << s << endl;

    if (cnt == n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}