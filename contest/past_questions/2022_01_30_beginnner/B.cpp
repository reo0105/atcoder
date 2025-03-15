#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a.at(i).at(j);
        }
    }

    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            cout << a.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}