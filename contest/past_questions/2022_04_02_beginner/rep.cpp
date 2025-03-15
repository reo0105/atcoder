#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n;
    int sx, sy, gx, gy;
    vector<string> s(1505);

    cin >> n >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    vector<int> dir_x = {1, -1, -1, 1};
    vector<int> dir_y = {-1, -1, 1, 1};

    queue<p> que;
    vector<vector<int>> dist(1505, vector<int>(1505, -1));
    dist.at(sx).at(sy) = 0;
    que.push(make_pair(sx, sy));

    while (que.size()) {
        p now = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                int nx = now.first  + j * dir_x.at(i);
                int ny = now.second + j * dir_y.at(i);

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || s.at(nx).at(ny) == '#') break;

                if (dist.at(nx).at(ny) == -1) {
                    dist.at(nx).at(ny) = dist.at(now.first).at(now.second) + 1;
                    que.push(make_pair(nx, ny));
                } else if (dist.at(nx).at(ny) <= dist.at(now.first).at(now.second)) break;
            }
        }
    }

    cout << dist.at(gx).at(gy) << endl;

    return 0;
}