#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h1, w1, h2, w2;
    cin >> h1 >> w1;

    vector<vector<int>> a(h1);
    vector<int> b;
    for (int i = 0; i < h1; i++) {
        for (int j = 1; j <= w1; j++) {
            int x;
            cin >> x;
            a.at(i).push_back(x);
        }
    }

    cin >> h2 >> w2;
    for (int i = 0; i < h2; i++) {
        for (int j = 1; j <= w2; j++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
    }

    int flag = 0;
    for (int i = 0; i < (1<<h1); i++) {
        for (int j = 0; j < (1<<w1); j++) {
            int cnt = 0;
            vector<int> era;
            for (int k = 0; k < h1; k++) {
                if (((i>>k) & 1) == 0) {
                    // cout << 2 << endl;
                    for (int l = 0; l < w1; l++) {
                        if (((j>>l) & 1) == 0) {
                            era.push_back(a.at(k).at(l));
                            // cout << 1 << endl;
                        }
                    }
                    cnt++;
                }
                if (cnt >= h2) break;
            }
            if (era == b) flag = 1;
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0; 
}
