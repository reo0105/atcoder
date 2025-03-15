#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int ans = 0;
    vector<vector<int>> done(h, vector<int>(w, -1));
    vector<int> dir_i = {0, -1, 0, 1};
    vector<int> dir_j = {1, 0, -1, 0};
    int cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (done[i][j] == -1 && s[i][j] != '#') {
                int t = 1;

                queue<pii> que;
                que.push(make_pair(i, j));
                done[i][j] = cnt;

                while (que.size()) {
                    int i = que.front().first;
                    int j = que.front().second;
                    que.pop();
                    bool ok = true;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dir_i[k];
                        int nj = j + dir_j[k];

                        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                        if (s[ni][nj] == '#') {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dir_i[k];
                            int nj = j + dir_j[k];

                            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;

                            if (done[ni][nj] != cnt) {
                                done[ni][nj] = cnt;
                                t++;
                                que.push(make_pair(ni, nj));
                            }
                        }
                    }
                }
                cnt++;
                ans = max(ans, t);
            }
        }
    }

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         cout << done[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;

    return 0;
}