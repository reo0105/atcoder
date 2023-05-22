#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(105);

    for (int i = 0; i < h; i++) cin >> s.at(i);

    vector<int> dir_x = {1, 0, -1, -1, -1, 1, 0, 1};
    vector<int> dir_y = {-1, -1, -1, 0, 1, 1, 1, 0};

    vector<char> tar = {'s', 'n', 'u', 'k', 'e'};

    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s.at(i).at(j) == 's') {
                // cout << i << " " << j << endl; 
                for (int k = 0; k < 8; k++) {
                    cnt = 1;
                    int nx = j + dir_x.at(k);
                    int ny = i + dir_y.at(k);
                    // cout << nx << " " << ny << endl;
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                    if (s.at(ny).at(nx) == 'n') {
                        cnt++;
                        nx = j + dir_x.at(k) * cnt;
                        ny = i + dir_y.at(k) * cnt;
                        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                        while (s.at(ny).at(nx) == tar.at(cnt)) {
                            cnt++;
                            nx = j + dir_x.at(k) * cnt;
                            ny = i + dir_y.at(k) * cnt;
                            // cout << nx << " " << ny << endl;
                            if (nx < 0 || nx >= w || ny < 0 || ny >= h || cnt == 5) break;
                        }
                        // cout << cnt << " ";  
                        if (cnt == 5) {
                            for (int ans = 0; ans < 5; ans++) {
                                cout << i + 1 + dir_y.at(k) * ans << " " << j + 1 + dir_x.at(k) * ans << endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
}