#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> dir_i = {0, -1, 0, 1};
    vector<int> dir_j = {1, 0, -1, 0};

    int ans = 0;

    const int INF = 1e9;
    vector<vector<int>> dist_a(n, vector<int>(n, INF));
    queue<pii> que_a;
    que_a.push(make_pair(0, 0));
    dist_a[0][0] = 0;

    while(que_a.size()) {
        int i = que_a.front().first;
        int j = que_a.front().second;
        que_a.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + dir_i[k];
            int nj = j + dir_j[k];

            if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            
            if (s[ni][nj] == 'R') {
                if (dist_a[ni][nj] > dist_a[i][j]) {
                    dist_a[ni][nj] = dist_a[i][j];
                    que_a.push(make_pair(ni, nj));
                }
            } else {
                if (dist_a[ni][nj] > dist_a[i][j]+1) {
                    dist_a[ni][nj] = dist_a[i][j]+1;
                    que_a.push(make_pair(ni, nj));
                }
            }
        }
    }

    vector<vector<int>> dist_b(n, vector<int>(n, INF));
    queue<pii> que_b;
    que_b.push(make_pair(0, n-1));
    dist_b[0][n-1] = 0;

    while(que_b.size()) {
        int i = que_b.front().first;
        int j = que_b.front().second;
        que_b.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + dir_i[k];
            int nj = j + dir_j[k];

            if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            
            if (s[ni][nj] == 'B') {
                if (dist_b[ni][nj] > dist_b[i][j]) {
                    dist_b[ni][nj] = dist_b[i][j];
                    que_b.push(make_pair(ni, nj));
                }
            } else {
                if (dist_b[ni][nj] > dist_b[i][j]+1) {
                    dist_b[ni][nj] = dist_b[i][j]+1;
                    que_b.push(make_pair(ni, nj));
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dist_a[n-1][n-1] + dist_b[n-1][0] << endl;

    return 0;
}