#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> p(n), c(n);
    vector<set<int>> f(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        for (int j = 0; j < c[i]; j++) {
            int t;
            cin >> t;
            f[i].insert(t);
        }
    }

    int ok = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int check = 1;
            if (p[i] == p[j]) {
                for (int fi : f[i]) {
                    if (!f[j].count(fi)) check = 0;
                }
                if (check && f[i].size() != f[j].size()) ok = 1;
            } else if (p[i] > p[j]) {
                for (int fi : f[i]) {
                    if (!f[j].count(fi)) check = 0;
                }
                if (check) ok = 1;
            }
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}