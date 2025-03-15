#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    int ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        m -= h;
        if (m < 0) break;
        ans++;
    }

    cout << ans << endl;
}