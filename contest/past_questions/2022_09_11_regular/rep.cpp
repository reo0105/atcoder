#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int l = -1, r;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'p') {
            l = i;
            break;
        }
    }

    if (l == -1) {
        cout << s << endl;
        return 0;
    }

    // cout << l << " " << maxi << endl;

    vector<int> t;
    int cnt = 0;
    for (int i = l; i < n; i++) {
        if (s.at(i) == 'p') cnt++;
        else if (cnt != 0) {
            t.push_back(i);
            cnt = 0;
        }
    }

    if (cnt != 0) t.push_back(n);

    string ans(n, 'z');
    for (int x : t) {
        // cout << l << " " << x << endl;
        string tmp;
        for (int i = 0; i < l; i++) tmp.push_back(s.at(i));
        for (int i = x-1; i >= l; i--) {
            if (s.at(i) == 'p') tmp.push_back('d');
            if (s.at(i) == 'd') tmp.push_back('p');
        }
        for (int i = x; i < n; i++) tmp.push_back(s.at(i));
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}