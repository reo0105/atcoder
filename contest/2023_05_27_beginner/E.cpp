#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> k(200005, 0);
    vector<vector<int>> G(200005);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        k.at(u)++;
        k.at(v)++;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    int cnt = 0;
    vector<int> levels;
    set<int> ones;
    set<int> centers;
    vector<bool> done(200005, false);

    for (int i = 1; i <= n; i++) {
        if (k.at(i) == 1) ones.insert(i);
    }

    // for (int x : ones) cout << x << " ";
    // cout << endl;

    while (ones.size()) {
        int one = *begin(ones);
        ones.erase(one);
        // if (k.at(i) == 1) {
        int center;// = G.at(one).at(0);
        // cout << center << " ";
        for (int x : G.at(one)) {
            if (done.at(x) == false) {
                center = x;
                break;
            }
        }
        if (done.at(center)) continue;
        if (centers.count(center)) continue;
        // cout << center << " ";
        done.at(center) = true;
        centers.insert(center);
        int lev = k.at(center);
        levels.push_back(lev);

        for (int edge : G.at(center)) {
            done.at(edge) = true;
            if (k.at(edge) != 1) {
                for (int t : G.at(edge)) {
                    if (t != center) {
                        ones.insert(t);
                    }
                }
            }
        }
        // }
    }

    sort(levels.begin(), levels.end());
    for (int ans : levels) cout << ans << " ";
    cout << endl;
    return 0;
}