#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    vector<int> h_idx, w_idx;

    for (int i = 0; i < h; i++) h_idx.push_back(i);
    for (int i = 0; i < w; i++) w_idx.push_back(i);
    
    int ans = 1e9;

    do {

        do {

            int ok = 1;
            for (int hi = 0; hi < h; hi++) {
                for (int wi = 0; wi < w; wi++) {
                    if (a[h_idx[hi]][w_idx[wi]] != b[hi][wi]) ok = 0;
                }
            }

            if (ok) {
                int temp = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = i+1; j < h; j++) {
                        if (h_idx[i] > h_idx[j]) temp++;
                    }
                }

                for (int i = 0; i < w; i++) {
                    for (int j = i+1; j < w; j++) {
                        if (w_idx[i] > w_idx[j]) temp++;
                    }
                }

                ans = min(ans, temp);
            }

        } while (next_permutation(w_idx.begin(), w_idx.end()));

    } while (next_permutation(h_idx.begin(), h_idx.end()));


    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}