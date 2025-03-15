#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    auto win = [&](vector<vector<int>> &nb) -> bool {
        bool ret = false;
        for (int i = 0; i < 3; i++) {
            if (nb[i][0] == nb[i][1] && nb[i][1] == nb[i][2] && nb[i][0] == 1) ret = true;
        }

        for (int i = 0; i < 3; i++) {
            if (nb[0][i] == nb[1][i] && nb[1][i] == nb[2][i] && nb[0][i] == 1) ret = true;
        }

        if (nb[0][0] == nb[1][1] && nb[1][1] == nb[2][2] && nb[0][0] == 1) ret = true;
        if (nb[0][2] == nb[1][1] && nb[1][1] == nb[2][0] && nb[0][2] == 1) ret = true;

        return ret;
    };

    auto f = [&](auto f, vector<vector<int>> b) -> bool {
        bool end = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == 0) end = false;
            }
        }

        if (end) {
            ll sum = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    sum += a[i][j] * b[i][j];
                }
            }
            return sum > 0;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][j] == 0) {
                    vector<vector<int>> nb = b;
                    nb[i][j] = 1;

                    if (win(nb)) return true;

                    for (int ii = 0; ii < 3; ii++) {
                        for (int jj = 0; jj < 3; jj++) {
                            nb[ii][jj] = -nb[ii][jj];
                        }
                    }

                    if (!f(f, nb)) return true;
                }
            }
        }

        return false;
    };

    vector<vector<int>> b(3, vector<int>(3));
    if (f(f, b)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}