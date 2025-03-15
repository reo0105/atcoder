#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    int pi, pj, qi, qj;
    int first = 1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'P') {
                if (first) {
                    pi = i, pj = j;
                    first = 0;
                } else {
                    qi = i, qj = j;
                }
            }
        }
    }

    vector<vector<int>> done(n*n, vector<int>(n*n, -1));

    vector<int> dir_i = {1, 0, -1, 0};
    vector<int> dir_j = {0, 1, 0, -1};

    queue<ppi> que;
    
    que.push(make_pair(make_pair(pi, pj), make_pair(qi, qj)));
    done[pi*n+pj][qi*n+qj] = 0;

    while (que.size()) {
        pii p = que.front().first;
        pii q = que.front().second;

        int pi = p.first;
        int pj = p.second;
        int qi = q.first;
        int qj = q.second;

        que.pop();

        for (int i = 0; i < 4; i++) {
            int npi = pi + dir_i[i];
            int npj = pj + dir_j[i];
            int nqi = qi + dir_i[i];
            int nqj = qj + dir_j[i];

            if (npi < 0 || npi >= n || s[npi][npj] == '#') npi -= dir_i[i];
            if (npj < 0 || npj >= n || s[npi][npj] == '#') npj -= dir_j[i];
            if (nqi < 0 || nqi >= n || s[nqi][nqj] == '#') nqi -= dir_i[i];
            if (nqj < 0 || nqj >= n || s[nqi][nqj] == '#') nqj -= dir_j[i];
        
            if (done[npi*n+npj][nqi*n+nqj] == -1) {
                done[npi*n+npj][nqi*n+nqj] = done[pi*n+pj][qi*n+qj] + 1;

                que.push(make_pair(make_pair(npi, npj), make_pair(nqi, nqj)));
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n*n; i++) {
        if (done[i][i] != -1) {
            ans = min(ans, done[i][i]);
        }
    }

    if (ans == 1e9) ans = -1;

    cout << ans << endl;


    return 0;
}