#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
<<<<<<< HEAD
 
=======

>>>>>>> 2024894da4c522d35d9aea587cfd6aed5c869099
int main()
{
    int t;
    cin >> t;
<<<<<<< HEAD
 
=======

>>>>>>> 2024894da4c522d35d9aea587cfd6aed5c869099
    for (int i = 0; i < t; i++) {
        ll n, ans;
        cin >> n;
        string s = to_string(n);
        int si = (int)s.size();
<<<<<<< HEAD
        int flag = 0;
        string nine;
        for (int i = 0; i < si-1; i++) nine.push_back('9');
        ans = stoll(nine);
        for (int j = 1; j <= si-1; j++) { //1周期j個に分割
            string loop;
            ll fir;
            if (si % j == 0) {
                for (int k = 0; k < j; k++) loop.push_back(s.at(k));
                // fir = stoll(loop);
                // cout << loop << endl;
                // for (int k = 1; k < si/j; k++) { //k周期
                //     string tmp;
                //     for (int l = 0; l < j; l++) { //j文字
                //         tmp.push_back(s.at(k*j+l));
                //     }
                //     ll sec = stoll(tmp);
                //     if (sec < fir) { flag = 1; break; }
                // }
                string t;
                ll l = stoll(loop);
                for (int k = 0; k < si/j; k++) {
                    t.append(loop);
                }
                fir = stoll(t);
                if (fir <= n) ans = max(ans, fir);
                else {
                    l--;
                    string tt = to_string(l);
                    string ttt;
                    for (int k = 0; k < si/j; k++) {
                        ttt.append(tt);
                    }
                    fir = stoll(ttt);
                    ans = max(ans, fir);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
=======
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
>>>>>>> 2024894da4c522d35d9aea587cfd6aed5c869099
}