#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> s(105), t(105);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i) >> t.at(i);

    int flag = 1;
    for (int i = 0; i < n; i++) {
        int cs = 0, ct = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (s.at(i) == s.at(j) || s.at(i) == t.at(j)) cs++;
            if (t.at(i) == t.at(j) || t.at(i) == s.at(j)) ct++;
        }

        if (cs != 0 && ct != 0) flag = 0;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}