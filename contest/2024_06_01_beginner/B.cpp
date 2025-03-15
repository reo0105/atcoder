#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<int> ans(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            ans[j] += x;
        }
    }

    int ok = 1;
    for (int i = 0; i < m; i++) {
        if (ans[i] < a[i]) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}