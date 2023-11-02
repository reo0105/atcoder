#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    string t;

    cin >> n >> t;
    string t_inv(t.rbegin(), t.rend());
    
    vector<string> s(n);
    vector<int> stoe(n, 0);
    vector<int> etos(n, 0);

    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) {
        int id = 0;

        for (int j = 0; j < (int)s[i].size(); j++) {
            if (s[i][j] == t[id]) {
                id++;
                stoe[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int id = 0;

        for (int j = (int)s[i].size()-1; j >= 0; j--) {
            if (s[i][j] == t_inv[id]) {
                id++;
                etos[i]++;
            }
        }
    }

    sort(stoe.begin(), stoe.end());
    sort(etos.begin(), etos.end());

    ll ans = 0;
    int sz = (int)t.size();

    for (int i = 0; i < n; i++) {
        int now = sz - stoe[i];

        ans += etos.end() - lower_bound(etos.begin(), etos.end(), now);
    }

    cout << ans << endl;

    return 0;
}