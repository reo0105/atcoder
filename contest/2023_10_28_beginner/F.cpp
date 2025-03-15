#include <bits/stdc++.h>
using namespace std;

string solve (vector<int> a, int x) {
    int n2 = (int)a.size();
    int n = n2 / 2;

    vector<int> al(a.begin(), a.begin()+n);
    vector<int> ar(a.begin()+n, a.end());

    unordered_map<int, string> mp;

    for (int pn = 0; pn < (1<<n); pn++) {
        string s;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (pn>>i&1) {
                s += "+", tot += al[i];
            } else {
                s += "-", tot -= al[i];
            }
        }
        mp[tot] = s;
    }

    for (int pn = 0; pn < (1<<n); pn++) {
        string s;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (pn>>i&1) {
                s += "+", tot += ar[i];
            } else {
                s += "-", tot -= ar[i];
            }
        }
        auto it = mp.find(x-tot);
        if (it != mp.end()) {
            return it->second + s;
        }
    }

    
    return "";
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int added = 0;
    while (n%4 != 0) n++, a.push_back(0), added++;

    vector<int> ax, ay;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ay.push_back(a[i]);
        else ax.push_back(a[i]);
    }

    string sx = solve(ax, x);
    string sy = solve(ay, y);

    if (sx == "" || sy == "") {
        cout << "No" << endl;
        return 0;
    }

    string ans;
    char pre = '+';
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (pre == sy[i/2]) ans += 'L';
            else ans += 'R';
            pre = sy[i/2];
        } else {
            if (pre == sx[i/2]) ans += 'R';
            else ans += 'L';
            pre = sx[i/2];
        }
    }

    for (int i = 0; i < added; i++) ans.pop_back();
    cout << "Yes" << endl;
    cout << ans << endl;

    return 0;
}