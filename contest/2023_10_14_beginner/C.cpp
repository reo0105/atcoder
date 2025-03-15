#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string t;
    cin >> n >> t;

    int sz = (int)t.size();
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int s_sz = (int)s.size();
        int ok = 1;

        if (sz == s_sz) {
            int cnt = 0;
            for (int j = 0; j < sz; j++) {
                if (t[j] != s[j]) cnt++;
            }
            if (cnt <= 1) ans.push_back(i);
        } else if (sz-1 == s_sz) {
            int diff = 0;
            int ids = 0;
            int idt = 0;
            while (diff <= 1 && idt < sz) {
                if (s[ids] == t[idt]) {
                    ids++;
                    idt++;
                } else {
                    idt++;
                    diff++;
                }
            }
            if (diff == 1) ans.push_back(i);
        } else if (sz+1 == s_sz) {
            int diff = 0;
            int ids = 0;
            int idt = 0;
            while (diff <= 1 && ids < s_sz) {
                if (t[idt] == s[ids]) {
                    idt++;
                    ids++;
                } else {
                    ids++;
                    diff++;
                }
            }
            if (diff == 1) ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;

    return 0;
}