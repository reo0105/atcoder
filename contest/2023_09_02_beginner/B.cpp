#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> xy(105, vector<int>(105, 0));

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < b; j++) {
            for (int k = c; k < d; k++) {
                xy[j][k] = 1;
            }
        }
    }

    int s = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (xy[i][j] == 1) s++;
        }
    }

    cout << s << endl;

    return 0;
}