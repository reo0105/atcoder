#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<map<int, vector<int>>> mp(3);

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            mp[i][s[j] - '0'].push_back(j);
        }
    }

    int ans = 1e9;

    vector<int> ids = {0, 1, 2};

    for (int i = 0; i < 10; i++) {
        if ((int)mp[0][i].size() != 0 && (int)mp[1][i].size() && (int)mp[2][i].size()) break;
        if (i == 9) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        do {
            int cnt = 0;
            int now = 0;
            int near = 1e9;
            int flag = 1;
            int first = 1;
            for (int id : ids) {
                if ((int)mp[id][i].size() == 0) {flag = 0; break; }
                for (int next : mp[id][i]) {
                    if (near > (next - now + n) % n) {
                        near = (next - now + n) % n;
                    }
                }
                for (int next : mp[id][i]) {
                    if (near == (next - now + n) % n) {
                        now = next;
                        cnt += near;
                    }
                }
                if (first == 0) cnt++;
                near = 1e9;
                now = now + 1 % n;
                first = 0;
                // cout << "now " << now << " " << cnt << endl;
            }
            // cout << flag << " " << cnt << endl;
            if (flag) ans = min(ans, cnt);
        } while (next_permutation(ids.begin(), ids.end()));
    }

    cout << ans << endl;

    return 0;
}