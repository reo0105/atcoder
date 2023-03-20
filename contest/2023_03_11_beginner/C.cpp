#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    vector<vector<int>> a(15, vector<int>(15));

    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a.at(i).at(j);
        }
    }
    
    int total = h+w-2;

    int ans = 0;
    for (int i = 0; i < (1<<total); i++) {
        int cnt = 0;
        for (int j = 0; j < total; j++) {
            if (((i>>j)&1) == 1) cnt++;
        }
        //iの1が下0が右
        if (cnt == h-1) {
            int flag = 1;
            int nh = 1, nw = 1;
            set<int> done;
            done.insert(a.at(1).at(1));
            for (int j = 0; j < total; j++) {
                if (((i>>j)&1) == 1) {
                    nh++;
                    if (done.count(a.at(nh).at(nw))) {
                        flag = 0;
                        break;
                    } else {
                        done.insert(a.at(nh).at(nw));
                    }
                } else {
                    nw++;
                    if (done.count(a.at(nh).at(nw))) {
                        flag = 0;
                    } else {
                        done.insert(a.at(nh).at(nw));
                    }
                }
            }

            if (flag) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}