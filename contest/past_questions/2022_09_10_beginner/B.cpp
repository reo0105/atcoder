#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;

    cin >> s >> t;

    int ns = (int)s.size();
    int nt = (int)t.size();

    int cnt = 0;
    if (ns > nt) { cout << "No" << endl; return 0; }
    while (1) {
        if (s.at(cnt) == t.at(cnt)) {
            cnt++;
        } else {
            break;
        }

        if (cnt == ns) break;
    }

    if (cnt == ns) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}