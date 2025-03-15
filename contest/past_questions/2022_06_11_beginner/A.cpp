#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    vector<vector<int>> a(2, vector<int>(2));

    cin >> r >> c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a.at(i).at(j);
        }
    }

    r--; c--;
    cout << a.at(r).at(c);

    return 0;
}