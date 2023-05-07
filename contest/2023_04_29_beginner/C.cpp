#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    vector<vector<char>> c(105, vector<char>(105));
    vector<int> ans(105, 0);


    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c.at(i).at(j);
        }
    }

    vector<int> dir_x = {1, -1 , -1, 1};
    vector<int> dir_y = {-1, -1 , 1, 1};

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (c.at(i).at(j) == '#') {
                int cnt = 1;
                int ni = i+1, nj = j+1;
                while (ni+1 <= h && nj-1 >= 1 && nj - 1 <= w && c.at(ni+1).at(nj-1) == '.') {
                    cnt++;
                    ni++;
                    nj++;
                }

                // cout << ni << " " << nj << " " << cnt << endl; 
                
                ans.at(cnt)++;
                if (ni >= 1 && ni <= h && nj >= 1 && nj <= w) c.at(ni).at(nj) = '.';

                for (int k = 0; k < 4; k++) {
                    for (int l = 1; l <= cnt; l++) {
                        int ti = ni+dir_y.at(k)*l;
                        int tj = nj+dir_x.at(k)*l;
                        if (ti <= 0 || ti > h || tj <= 0 || tj > w) continue;
                        c.at(ti).at(tj) = '.';
                    }
                }

            }
        }
    }

    int n = min(h, w);
    for (int i = 1; i <= n; i++) cout << ans.at(i) << " ";
    cout << endl;
    return 0;
}