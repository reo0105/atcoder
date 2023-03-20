#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int fir = -1;

        for (int i = 0; i < n; i++) {
            if (s.at(i) == '1') {
                k--;
                fir = i;
                break;
            }
        }

        int cnt = 0;
        int l = 0, r = n-1;
        int ok = 1;

        if (fir != -1) {
            for (int i = fir+1; i < n; i++) {
                if (s.at(i) == '0' || (cnt == k && s.at(i) == '?')) {
                    r = i-1;
                    break;
                }
                if (s.at(i) == '?' || s.at(i) == '1') cnt++;
            }

            // cout << cnt << " " << k << endl;

            for (int i = fir-1; i >= 0; i--) {
                if (s.at(i) == '0' || (cnt == k && s.at(i) == '?')) {
                    l = i+1;
                    break;
                }
                if (s.at(i) == '?' || s.at(i) == '1') cnt++;
            }
        } else {
            int t = 0;
            map<int, int> mp;
            for (int i = 0; i < n; i++) {
                if (s.at(i) == '?') t++;
                else {
                    mp[t]++;
                    cnt = max(cnt, t);
                    t = 0;
                }
            }
            mp[t]++;
            cnt = max(cnt, t);
            if (mp[cnt] != 1) ok = 0;
        }


        // cout << cnt << " " << l << " " << r << endl;

        if (cnt == k) {
            for (int i = 0; i < l; i++) {
                if(s.at(i) == '1') ok = 0;
            }
            for (int i = r+1; i < n; i++) {
                if (s.at(i) == '1') ok = 0;
            }
            if (l > 0 && s.at(l-1) == '?' && s.at(r) == '?') ok = 0;
            if (r+1 < n && s.at(l) == '?' && s.at(r+1) == '?') ok = 0;
        } else {
            ok = 0;
        }

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}