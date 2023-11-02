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
                s[i][j] = 'x';

                while (que.size()) {
                    int ui = que.front().first;
                    int uj = que.front().second;
                    que.pop();


                    for (int k = 0; k < 8; k++) {
                        int ni = ui + dir_i[k];
                        int nj = uj + dir_j[k];

                        if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == 'x') continue;

                        if (s[ni][nj] == '#') {
                            s[ni][nj] = 'x';
                            que.push(make_pair(ni, nj));
                        }
                    }
                } 
            } else {
                s[i][j] = 'x';
            }
        }
    }

    cout << cnt << endl;

    return 0;
}