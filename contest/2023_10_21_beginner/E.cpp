#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);

    for (int i = 0; i < h; i++) cin >> s[i];

    int cnt = 0;
    vector<int> dir_i = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> dir_j = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0 ; i < h; i++) {
        for (int j = 0; j < w; j++) {
            queue<pii> que;
            if (s[i][j] == '#') {
                cnt++;
                que.push(make_pair(i, j));

                while (que.size()) {
                    int ui = que.front().first;
                    int uj = que.front().second;
                    que.pop();

                    s[ui][uj] = '.';

                    for (int k = 0; k < 8; k++) {
                        int ni = ui + dir_i[k];
                        int nj = uj + dir_j[k];

                        if (s[ni][nj] == '#') {
                            que.push(make_pair(ni, nj));
                        }
                    }
                } 
            }
        }
    }

    cout << ans << endl;

    return 0;
}