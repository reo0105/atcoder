#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<set<int>> to(300005); //自分がどれと繋がっているか
    // vector<set<int>> who(300005);

    int ans = n;
    for (int i = 0; i < q; i++) {
        int qi, u, v;
        cin >> qi;
        if (qi == 1) {
            cin >> u >> v;
            if (to.at(u).empty()) ans--;
            if (to.at(v).empty()) ans--;
            to.at(u).insert(v);
            to.at(v).insert(u);
        } else {
            cin >> v;
            if (!to.at(v).empty())ans++;
            for (int x : to.at(v)) {
                to.at(x).erase(v);
                if (to.at(x).empty()) ans++;
            }
            to.at(v).clear();
        }
        cout << ans << '\n';
    }
    return 0;
}