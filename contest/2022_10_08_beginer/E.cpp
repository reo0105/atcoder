#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> a(200005);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<set<int>> cnt(200005);

    for (int i = 1; i <= n; i++) {
        int s = ceil(-a.at(i) / i);
        if (s <= 0) s = 1;
        int e = (n - a.at(i)) / i;

        for (int j = s; j <= e; j++) {
            if (j > m) break;
            cnt.at(j).insert(a.at(i)+i*j);
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j : cnt.at(i)) cout << j << " ";
    //     cout << endl;
    // }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (!cnt.at(i).count(j)) {
                cout << j << '\n';
                break;
            }
        }
    }

    return 0;
}