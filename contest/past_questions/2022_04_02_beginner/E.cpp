#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;
    int ax, ay;
    int bx, by;
    vector<string> s(1505);

    cin >> n >> ax >> ay >> bx >> by;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    queue<p> que;
    vector<vector<int>> dist(1505, vector<int>(1505, -1));
    vector<int> dir_x = {-1, -1, 1, 1};
    vector<int> dir_y = {1, -1, -1, 1};

    ax--; ay--;
    bx--; by--;
    que.push(make_pair(ax, ay));
    dist.at(ax).at(ay) = 0;

    while(!que.empty()) {
        int ux = que.front().first;
        int uy = que.front().second;
        que.pop();

        // if (dist.at(ux).at(uv))

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < n; j++) {
                int vx = ux + dir_x.at(i)*j;
                int vy = uy + dir_y.at(i)*j;

                if (vx < 0 || vx >= n || vy < 0 || vy >= n) break;
                if (s.at(vx).at(vy) == '#') break;
                if (dist.at(vx).at(vy) == -1) {
                    dist.at(vx).at(vy) = dist.at(ux).at(uy) + 1;
                    que.push(make_pair(vx, vy));
                } else if (dist.at(vx).at(vy) <= dist.at(ux).at(uy)) break;
            } 
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dist.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    if (dist.at(bx).at(by) != -1) cout << dist.at(bx).at(by) << endl;
    else cout << dist.at(bx).at(by) << endl;

    return 0;
}