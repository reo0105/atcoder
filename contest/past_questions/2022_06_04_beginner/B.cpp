#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(35, vector<int>(35, 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) cout << 1 << " ";
            else {
                a.at(i).at(j) = a.at(i-1).at(j-1) + a.at(i-1).at(j);
                cout << a.at(i).at(j) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}