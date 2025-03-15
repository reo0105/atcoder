#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; i++) cin >> a[i];

    int n;
    cin >> n;
    vector<vector<int>> es(h, vector<int>(w, -1));

    for (int i = 0; i < n; i++) {
        int r, c, e;
        cin >> r >> c >> e;
        r--; c--;
        es[r][c] = e;
    }

    int si, sj;
    int gi, gj;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'S') {
                si = i; sj = j;
            } else if (a[i][j] == 'T') {
                gi = i; gj = j;
            }
        }
    }

    queue<ppi> que;
    vector<vector<int>> done(h, vector<int>(w, -1));

    que.push(make_pair(make_pair(si, sj), es[si][sj]));
    done[si][sj] = es[si][sj];

    vector<int> dir_i = {0, -1, 0, 1};
    vector<int> dir_j = {1, 0, -1, 0};

    while (que.size()) {
        int ui = que.front().first.first;
        int uj = que.front().first.second;
        int e = que.front().second;
        que.pop();

        if (done[ui][uj] != e) continue;
        if (e <= 0) continue;

        e--;

        for (int i = 0; i < 4; i++) {
            int vi = ui + dir_i[i];
            int vj = uj + dir_j[i];

            if (vi < 0 || vj < 0 || vi >= h || vj >= w) continue;
            if (a[vi][vj] == '#') continue;

            int ne = max(e, es[vi][vj]);

            if (done[vi][vj] < ne) {
                done[vi][vj] = ne;
                que.push(make_pair(make_pair(vi, vj), ne));
            }

        }
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         cout << done[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
    }

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         cout << done[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (done[gi][gj] != -1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}