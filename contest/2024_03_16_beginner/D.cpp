#include <bits/stdc++.h>
using namespace std;


bool check(int n, int h, int w, vector<int> &a, vector<int> &b)
{
    vector<vector<bool>> mp(h, vector<bool>(w, false));
    int id = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!mp[i][j]) {
                if (id == n) return false;
                for (int pi = 0; pi < a[id]; pi++) {
                    for (int pj = 0; pj < b[id]; pj++) {
                        if (i+pi >= h || j+pj >= w) return false;
                        if (mp[i+pi][j+pj]) return false;

                        mp[i+pi][j+pj] = true;
                    }
                }

                id++;
            }
        }
    }

    return true;
}

int main()
{
    int n, h, w;

    cin >> n >> h >> w;
    vector<int> A(n), B(n), a(n), b(n);
    vector<int> idx(n);

    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < n; i++) idx[i] = i;

    do {
        for (int s = 0; s < (1<<n); s++) {
            for (int i = 0; i < n; i++) {
                a[i] = A[idx[i]];
                b[i] = B[idx[i]];
                if ((s >> i) & 1) swap(a[i], b[i]); 
            }

            if (check(n, h, w, a, b)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    } while(next_permutation(idx.begin(), idx.end()));

    cout << "No" << endl;

    return 0;
}

