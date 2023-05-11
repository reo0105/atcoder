#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    vector<vector<char>> a(35, vector<char>(35));
    vector<vector<char>> b(35, vector<char>(35));

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a.at(i).at(j);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b.at(i).at(j);
        }
    }

    for (int s = 0; s < h; s++) {
        for (int t = 0; t < w; t++) {
            int cnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (a.at((i+s)%h).at((j+t)%w) == b.at(i).at(j)) {
                        cnt++;
                    }
                }
            }
            if (cnt == h*w) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}