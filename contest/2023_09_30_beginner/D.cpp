#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<string>> p(3, vector<string>(4));

    int i0, j0;
    int i1, j2;
    int i2, j2;
    for (int i = 0; i < 3; i) {
        for (int j = 0; j < 4; j++) {
            cin >> p[i][j];
        }

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (p[i][k][j]) {
                    if (i == 0) {i0 = k; j0 = j; goto out;}
                    if (i == 1) {i1 = k; j1 = j; goto out;}
                    if (i == 2) {i2 = k; j2 = j; goto out;}
                }
            }
        }
out:
    }

    vector<vector<int>> done(4, vector<int>(4, 0));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int r = 0; r < 64; r++) {
                int r1 = r & 3;
                int r2 = (r & 12) >> 2;
                int r3 = (r & 48) >> 4;

                if (r1 == 0) {
                    for (int l0 = 0; l0 < 4; l0++) {
                        for (int l1 = 0; l1 < 4; l1++) {
                            done[l0][l1]
                        }
                    }
                }
            }
        }
    }

    return 0;
}