#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    vector<int> p(200005, 0);
    vector<int> child(200005, 0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) cin >> p.at(i);
    for (int i = 2; i <= n; i++) {
        child.at(p.at(i))++;
    }

    for (int i = 0; i < q; i++) {
        int m, ans = 0;
        set<int> s;

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            ans += child.at(x)+1;
            s.insert(x);
        }

        for (int x : s) {
            if (s.count(p.at(x))) ans -= 2;
        }

        cout << ans << endl;
    }

    return 0;
}