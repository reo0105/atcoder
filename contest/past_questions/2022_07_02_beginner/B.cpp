#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, maxi = 0;
    vector<vector<int>> a(15, vector<int>(15));
    vector<int> dir_x = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dir_y = {0, -1, -1, -1, 0, 1, 1, 1};

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            a.at(i).at(j) = s.at(j-1) - '0';
            maxi = max(maxi, a.at(i).at(j));
        }
    }

    string ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a.at(i).at(j) == maxi) {
                // cout << maxi << " " << i << " " << j << endl;
                for (int k = 0; k < 8; k++) {
                    string t;
                    for (int l = 0; l < n; l++) {
                        int nx = i + l*dir_x.at(k);
                        int ny = j + l*dir_y.at(k);

                        if (nx < 1) nx += n;
                        else if (nx > n) nx -= n;
                        if (ny < 1) ny += n;
                        else if (ny > n) ny -= n;
                        // cout << nx << " " << ny << endl;
                        t.push_back(a.at(nx).at(ny) + '0');
                    }
                    // cout << t << endl;
                    ans = max(ans, t);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}