#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, q;
    vector<vector<int>> G(1502, vector<int>(1502, 0));

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> G.at(i).at(j);
        }
    }

    for(int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            G.at(i).at(j) = G.at(i-1).at(j) + G.at(i).at(j-1) - G.at(i-1).at(j-1) + G.at(i).at(j);
        }
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans;
        ans = G.at(c).at(d) - G.at(a-1).at(d) - G.at(c).at(b-1) + G.at(a-1).at(b-1);
        cout << ans << endl;
    }

    return 0;
}