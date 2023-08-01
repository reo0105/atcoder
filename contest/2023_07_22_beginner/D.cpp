#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(205);

    for (int i = 0; i < n; i++) cin >> s.at(i);

    vector<vector<vector<int>>> dist(205, vector<vector<int>>(205, vector<int>(4, -1)));

    int ans = 0;

    queue<pi> que;
    que.push(make_pair(1, 1));

    vector<int> dir_i = {1, 0, -1, 0};
    vector<int> dir_j = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) dist.at(1).at(1).at(i) = 1;

    while (que.size()) {
        int now_i = que.front().first;
        int now_j = que.front().second;
        que.pop();
        // cout << now_i << " " << now_j << endl;

        for (int k = 0; k < 4; k++) {
            int maxi = (k % 2 == 1) ? m : n;
            for (int l = 1; l < maxi; l++) {
                int ni = now_i + dir_i.at(k) * l;
                int nj = now_j + dir_j.at(k) * l;
                // if (ni == 0 && nj == 20) {
                //     cout << ni << " " << nj <<  " "<< k <<endl;
                // }

                // if (ni < 1 || nj < 1 || ni >= n || nj >= m) break;
                if (dist.at(ni).at(nj).at(k) != -1) break;
                dist.at(ni).at(nj).at(k) = 1;

                if (s.at(ni).at(nj) == '#') {
                    que.push(make_pair(ni-dir_i.at(k), nj-dir_j.at(k)));
                    // if (ni == 1 && nj == 20) {
                    //     cout << ni << " " << nj <<  " "<< k <<endl;
                    // }
                    break;
                } 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s.at(i).at(j) == '.') {
                int k;
                for (k = 0; k < 4; k++) {
                    if (dist.at(i).at(j).at(k) != -1) {
                        ans++;
                        // cout << "1 ";  
                        break;
                    }
                }
                // if (k == 4) cout << "2 ";
            }
                // cout << "0 ";
            
        }
        // cout << endl;
    }

    cout << ans << endl;

    return 0;
}