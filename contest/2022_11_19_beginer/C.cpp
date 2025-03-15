#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    // vector<int> t(200002), a(200002), b(200002);
    map<int, set<int>> ff;

    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            ff[a].insert(b);
        } else if (t == 2) {
            if (ff[a].count(b)) {
                ff[a].erase(b);
            }
        } else {
            if (ff[a].count(b) && ff[b].count(a)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}