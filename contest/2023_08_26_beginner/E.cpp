#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int si, sj, gi, gj;

    set<char> ng;
    ng.insert('>');
    ng.insert('v');
    ng.insert('<');
    ng.insert('^');
    ng.insert('S');
    ng.insert('G');
    ng.insert('#');

    vector<vector<bool>> done(h, vector<bool>(w, false));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'S') si = i, sj = j;
            else if (s[i][j] == 'G') gi = i, gj = j;
            else if (s[i][j] == 'v') {
                for (int k = 1; k < h; k++) {
                    int ni = i + k;
                    if (ni >= h || ng.count(s[ni][j])) break;
                    s[ni][j] = '!';
                }
            } else if (s[i][j] == '>') {
                for (int k = 1; k < w; k++) {
                    int nj = j + k;
                    if (nj >= w || ng.count(s[i][nj])) break;
                    s[i][nj] = '!';
                }
            } else if (s[i][j] == '^') {
                for (int k = 1; k < h; k++) {
                    int ni = i - k;
                    if (ni < 0 || ng.count(s[ni][j])) break;
                    s[ni][j] = '!';
                }
            } else if (s[i][j] == '<') {
                for (int k = 1; k < w; k++) {
                    int nj = j - k;
                    if (nj < 0 || ng.count(s[i][nj])) break;
                    s[i][nj] = '!';
                }
            }
        }
    }

    queue<pii> que;
    vector<vector<int>> ans(h, vector<int>(w, -1));
    que.push(make_pair(si, sj));
    ans[si][sj] = 0;

    vector<int> dir_i = {0, -1, 0, 1};
    vector<int> dir_j = {1, 0, -1, 0};

    ng.insert('!');
    ng.erase('G');

    while (que.size()) {
        pii u = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int ni = u.first + dir_i[i];
            int nj = u.second + dir_j[i];

            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (ng.count(s[ni][nj])) continue;
            if (ans[ni][nj] != -1) continue;

            ans[ni][nj] = ans[u.first][u.second] + 1;
            que.push(make_pair(ni, nj));
        }
    }
    // for (int i = 0; i < h; i++) cout << s[i] << endl;
    // for (int i = 0; i < h; i++) {
        // for (int j = 0; j < w; j++) {
            // cout << ans[i][j] << " ";
        // }
        // cout << endl;
    // }

    cout << ans[gi][gj] << endl;

    return 0;
}