#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) != t.at(i)) cnt++;
    }

    if (cnt % 2) {
        cout << -1 << endl;
        return 0;
    }

    string ans(n, '0');
    int ds = cnt / 2, dt = cnt / 2;

    for (int i = 0; i < n; i++) {
        if (s.at(i) != t.at(i)) {
            if (s.at(i) == '0' && ds != 0) {
                ds--;
            } else if (t.at(i) == '0' && dt != 0) {
                dt--;
            } else {
                ans.at(i) = '1';
            }
        }
    }

    cout << ans << endl;

    return 0;    
}