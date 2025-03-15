#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, h, w;
    cin >> n >> h >> w;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];

    auto check = [&](vector<int> a, vector<int> b) -> bool {

        int id = 0;
        vector<vector<bool>> mp(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!mp[i][j]) {
                    if (id == n) return false;
                    for (int pi = 0; pi < a[id]; pi++) {
                        for (int pj = 0; pj < b[id]; pj++) {
                            int ni = i+pi;
                            int nj = j+pj;
                            if (ni < 0 || nj < 0 || ni >= h || nj >= w) return false;
                            if (mp[ni][nj]) return false;

                            mp[ni][nj] = true;
                        }
                    }
                    id++;
                }
            }
        }

        return true;

    };

    vector<int> ids;
    for (int i = 0; i < n; i++) ids.push_back(i);

    do {

        for (int s = 0; s < (1<<n); s++) {
            vector<int> a(n), b(n);
            for (int i = 0; i < n; i++) {
                a[i] = A[ids[i]];
                b[i] = B[ids[i]];
                if ((s>>i)&1) {
                    swap(a[i], b[i]);
                }
            }

            if (check(a, b)) {
                cout << "Yes" << endl;
                return 0;
            }
        }

    } while (next_permutation(ids.begin(), ids.end()));

    cout << "No" << endl;

    return 0;
}