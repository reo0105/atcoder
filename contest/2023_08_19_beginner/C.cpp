#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> fs(n+1);
    vector<pii> total;
    for (int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        fs[f].push_back(s);
        total.emplace_back(s, f);
    }

    sort(total.rbegin(), total.rend());
    for (int i = 1; i <= n; i++) {
        sort(fs[i].rbegin(), fs[i].rend());
    }

    int ans = 0;
    int maxi = total[0].first;
    for (int i = 1; i < n; i++) {
        if (total[0].second != total[i].second) {
            ans = maxi + total[i].first;
            break;
        }
    }
    // cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        if (fs[i].size() > 1) ans = max(ans, fs[i][0] + fs[i][1]/2);
    }

    cout << ans << endl;

    return 0;
}