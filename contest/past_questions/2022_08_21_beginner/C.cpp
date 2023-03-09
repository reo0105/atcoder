#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int h, w;
    vector<vector<char>> G(505, vector<char>(505));
    set<p> s;

    int x = 1, y = 1;
    s.insert(make_pair(x, y));

    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> G.at(i).at(j);
        }
    }

    int loop = 0;
    while (1) {
        int nx, ny;
        if (G.at(x).at(y) == 'U') {
            nx = x-1;
            ny = y;
        } else if (G.at(x).at(y) == 'D') {
            nx = x+1;
            ny = y;
        } else if (G.at(x).at(y) == 'R') {
            nx = x;
            ny = y+1;
        } else {
            nx = x;
            ny = y-1;
        }

        if (nx <= 0 || nx > h || ny <= 0 || ny > w) break;

        x = nx;
        y = ny;
        if (s.count(make_pair(x, y))) { loop = 1; break; }
        s.insert(make_pair(x, y));
    }

    if (loop) cout << -1 << endl;
    else cout << x << " " << y << endl;

    return 0;
}