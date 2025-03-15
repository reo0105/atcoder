#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<set<int>> colors(n);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        colors[i].insert(c);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (colors[a].size() > colors[b].size()) {
            for (int c : colors[b]) {
                colors[a].insert(c);
            }
            colors[b].clear();
            swap(colors[a], colors[b]);
        } else {
            for (int c : colors[a]) {
                colors[b].insert(c);
            }
            colors[a].clear();
        }

        cout << colors[b].size() << '\n';
    }

    return 0;
}
