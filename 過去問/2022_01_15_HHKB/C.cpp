#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    map<int, vector<int>> a;

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        if ((a.count(x) && k > (int)a.at(x).size()) || !a.count(x)) {
            cout << -1 << endl;
        } else {
            cout << a.at(x).at(k-1) << endl;
        }
    }

    return 0;
}