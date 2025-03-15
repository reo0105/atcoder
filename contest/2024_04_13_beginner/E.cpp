#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    int n = 3;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    auto win = [&](vector<vector<int>> b) -> bool {
        for (int ri = 0; ri < 2; ri++) {
            for (int i = 0; i < n; i++) {
                bool ok = true;
                for (int j = 0; j < n; j++) {
                    if (b[i][j] != 1) ok = false;
                }
                if (ok) return true;
            }
            if (b[0][0] == 1 && b[1][1] == 1 && b[2][2] == 1) return true;
            vector<vector<int>> old = b;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = old[n-1-j][i];
                }
            }
        }
        return false;
    };

    auto f = [&](auto f, vector<vector<int>> &b) -> bool {
        bool end = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 0) end = false;
            }
        }
        if (end) {
            ll s = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    s += a[i][j] * b[i][j];
                }
            }
            return s > 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 0) {
                    vector<vector<int>> nb = b;
                    nb[i][j] = 1;
                    if (win(nb)) return true;
                    for (int ni = 0; ni < n; ni++) {
                        for (int nj = 0; nj < n; nj++) {
                            nb[ni][nj] = -nb[ni][nj];
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