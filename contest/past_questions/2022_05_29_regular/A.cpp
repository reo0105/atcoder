#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n, ans;
        cin >> n;
        string s = to_string(n);
        int si = (int)s.size();
        int flag = 1;
        string nine;
        for (int i = 0; i < si-1; i++) nine.push_back('9');
        ans = stoll(nine);
        for (int j = 1; j <= si/2; j++) { //1周期j個に分割
            string loop;
            if (si % j == 0) {
                for (int k = 0; k < j; k++) loop.push_back(s.at(k));

                for (int k = 1; k < si/j; k++) { //k周期
                    for (int l = 0; l < j; l++) { //j文字
                        if (flag && loop.at(l) < s.at(k*j+l)) { goto out; }
                        else if (loop.at(l) > s.at(k*j+l)) { flag = 0; goto out; }
                    }
                }
            out:
                // cout << loop << " " << flag << endl;
                string t;
                for (int k = 0; k < si/j; k++) {
                    t.append(loop);
                }
                ll l = stoll(t);
                if (l > ans && l <= n) ans = l;
            }
            flag = 1;
        }
        cout << ans << endl;
    }
}