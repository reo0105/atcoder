#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N, h, w;
    vector<vector<int>> a(302, vector<int>(302, -1));
    vector<vector<int>> ans(302, vector<int>(302, 0));
    set<int> s;
    map<int, int> cnt;
 
    cin >> H >> W >> N >> h >> w;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (0 <= i && i < h && 0 <= j && j < w) {
                continue;
            } else {
                // set.insert(a.at(i).at(j));
                if (cnt.count(a.at(i).at(j))) {
                    cnt[a.at(i).at(j)] += 1;
                } else {
                    cnt[a.at(i).at(j)] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (cnt.count(i) && cnt[i] != 0) {
            ans.at(0).at(0) += 1;
        }
    }


    // int cnt = 0;
    for (int k = 0; k <= H-h; k++) {
        for (int l = 0; l <= W-w;l++) {
            if (l == 0 && k == 0 && W != w) continue;
            if (l == 0 && k == 0) {
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        cnt[a.at(k+i).at(l+j)] += 1;
                    }
                }
                continue;
            }
            if (l == 0) {
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        cnt[a.at(k+i).at(l+j)] -= 1;
                    }
                }
            } else {
                for (int i = 0; i < h; i++) {
                    cnt[a.at(k+i).at(l-1)] += 1;
                }
                for (int i = 0; i < h; i++) {
                    cnt[a.at(k+i).at(l+w-1)] -= 1;
                }
            }

            for (int i = 1; i <= N; i++) {
                if (cnt.count(i) && cnt[i] != 0) {
                    ans.at(k).at(l) += 1;
                }
            }

            if (l == W-w) {
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        cnt[a.at(k+i).at(l+j)] += 1;
                    }
                }
            }

        }
    }

    for (int k = 0; k <= H-h; k++) {
        for (int l = 0; l <= W-w;l++) {
            cout << ans.at(k).at(l) << " ";
        }
        cout << endl;
    }

    return 0;
}