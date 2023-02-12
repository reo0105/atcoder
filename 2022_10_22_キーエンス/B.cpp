#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    // vector<vector<int>> data(1002, vector<int>(1002));
    vector<int> ans(1002, 0);
    char tmp;

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> tmp;
            if (tmp == '#') {
                ans.at(j) += 1;
            }
        }
    }

    for (int i = 1; i <= w; i++) {
        cout << ans.at(i);
        if (i != w) cout << " ";
        else cout << endl;
    }
    
    return 0;
}