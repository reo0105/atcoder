#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(405, vector<int>(405, -1));
    vector<pi> tmp, dir;

    for (int i = 0; i*i <= m; i++) {
        for (int j = 0; j*j <= m; j++) {
            if (i*i + j*j == m) tmp.push_back(make_pair(i, j));
        }
    }

    for (pi t : tmp) {
        dir.push_back(make_pair(t.first, t.second));
        dir.push_back(make_pair(-t.first, t.second));
        dir.push_back(make_pair(t.first, -t.second));
        dir.push_back(make_pair(-t.first, -t.second));
    }

    // for (pi t : dir) cout << t.first << " " << t.second << endl;

    dist.at(1).at(1) = 0;
    queue<pi> que;
    que.push(make_pair(1, 1));

    while (que.size()) {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();

        for (pi t : dir) {
            int ni = i + t.first;
            int nj = j + t.second;

            if (ni <= 0 || nj <= 0 || ni > n || nj > n) continue;
            if (dist.at(ni).at(nj) != -1) continue;
            que.push(make_pair(ni, nj));
            dist.at(ni).at(nj) = dist.at(i).at(j) + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}