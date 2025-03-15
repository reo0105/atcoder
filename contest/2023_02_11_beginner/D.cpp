#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x;
    vector<int> a(100005);
    set<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    cin >> m;
    for (int i = 0; i < m; i++) { int b; cin >> b; s.insert(b); }
    cin >> x;

    vector<int> dp(100005, 0);

    dp.at(0) = 1;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a.at(j) && dp.at(i-a.at(j)) == 1) {
                if (s.count(i)) dp.at(i) = 2;
                else dp.at(i) = 1;
            }
        }
    }

    if (dp.at(x) != 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}