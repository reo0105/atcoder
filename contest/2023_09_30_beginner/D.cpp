#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3, m = 4;
    vector p(n, vector<string>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }

    vector<vector<vector<string>>> s(3);

    for (int pi = 0; pi < n; pi++) {
        for (int r = 0; r < 4; r++) {
            for (int di = -m; di < m; di++) {
                for (int dj = -m; dj < m; dj++) {
                    vector np(m, string(m, '.'));
                    bool ok = true;

                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < m; j++) {
                            if (p[pi][i][j] == '.') continue;
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni < 0 || nj < 0 || ni >= m || nj >= m) {
                                ok = false;
                                continue;
                            }
                            np[ni][nj] = '#';
                        }
                    }
                    if (!ok) continue;
                    s[pi].push_back(np);
                }
            }

            {
                auto pre = p[pi];
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        p[pi][i][j] = pre[m-1-j][i];
                    }
                }
            }
        }
    }

    for (auto p0 : s[0]) {
        for (auto p1 : s[1]) {
            for (auto p2 : s[2]) {
                vector<vector<int>> cnt(m, vector<int>(m, 0));

                auto put = [&](vector<string> p) {
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < m; j++) {
                            if (p[i][j] == '#') cnt[i][j]++;
                        }
                    }
                };
                put(p0);
                put(p1);
                put(p2);
                // cout << s[0].size() << " " << s[1].size() << " " << s[2].size() << endl;

                if (cnt == vector(m, vector<int>(m, 1))) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;


    return 0;
}