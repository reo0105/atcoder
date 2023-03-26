#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;

    cin >> r >> c;

    vector<vector<char>> m(25, vector<char>(25));
    vector<int> dir_x = {1, 0, -1, 0, 1, 1, -1, -1};
    vector<int> dir_y = {0, 1, 0, -1, 1, -1, 1, -1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m.at(i).at(j);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m.at(i).at(j) == '.' || m.at(i).at(j) == '#') continue;

            int p = m.at(i).at(j) - '0';
            m.at(i).at(j) = '.';
            for (int k = 0; k <= p; k++) {
                for (int l = 0; l <= p; l++) {
                    for (int ll = 0; ll < 8; ll++) {
                        if (k +l > p) continue;
                        // cout << k << " " << l << endl;
                        int nx = i + dir_x.at(ll) * k;
                        int ny = j + dir_y.at(ll) * l;
                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if (m.at(nx).at(ny) == '#') m.at(nx).at(ny) = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}