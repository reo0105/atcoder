#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    
    int n;
    string t;
    cin >> n >> t;

    vector<int> front(n, 0);
    vector<int> back(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int id = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (t[id] == s[j]) {
                id++;
                if (id == (int)t.size()) break;
            }
        }
        front[i] = id;

        id = (int)t.size()-1;
        for (int j = (int)s.size()-1; j >= 0; j--) {
            if (t[id] == s[j]) {
                id--;
                if (id == -1) break;
            }
        }
        back[i] = (int)t.size() - 1 - id;
    }

    ll ans = 0;
    sort(back.begin(), back.end());
    for (int i = 0; i < n; i++) {
        int now = (int)t.size() - front[i];
        ans += back.end() - lower_bound(back.begin(), back.end(), now);
    }

    cout << ans << endl;

    return 0;
}