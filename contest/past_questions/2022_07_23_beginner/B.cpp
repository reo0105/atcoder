#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<vector<char>> a(1005, vector<char>(1005));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a.at(i).at(j);
        }
    }

    int flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int ti = j;
            int tj = i;
            if (a.at(i).at(j) == '-' && a.at(ti).at(tj) != '-') flag = 0;
            else if (a.at(i).at(j) == 'W' && a.at(ti).at(tj) != 'L') flag = 0;
            else if (a.at(i).at(j) == 'D' && a.at(ti).at(tj) != 'D') flag = 0;
            else if (a.at(i).at(j) == 'L' && a.at(ti).at(tj) != 'W') flag = 0;
        }
    }

    if (flag) cout << "correct" << endl;
    else cout << "incorrect" << endl;

    return 0;
}