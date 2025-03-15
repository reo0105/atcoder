#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n;
    vector<vector<int>> G(1502, vector<int>(1502, 0));
    cin >> h >> w >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        G.at(a).at(b) += 1;
        G.at(a).at(d+1) -= 1;
        G.at(c+1).at(b) -= 1;
        G.at(c+1).at(d+1) += 1;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            G.at(i).at(j) = G.at(i).at(j-1) + G.at(i-1).at(j) - G.at(i-1).at(j-1) + G.at(i).at(j);
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << G.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}