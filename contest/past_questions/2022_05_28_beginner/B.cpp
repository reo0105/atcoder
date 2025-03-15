#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    int cnt = 0;
    int ux, uy, vx, vy;
    vector<string> s(105);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s.at(i);
        for (int j =0; j < w; j++) {
            if (cnt == 0 && s.at(i).at(j) == 'o') { cnt++; ux = i; uy = j; }
            else if (cnt == 1 && s.at(i).at(j) == 'o') { vx = i; vy = j; }
        }
    }

    cout << abs(ux-vx) + abs(uy-vy) << endl;

    return 0;
}