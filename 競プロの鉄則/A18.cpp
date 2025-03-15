#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    vector<int> a(62);
    vector<vector<bool>> dp(62, vector<bool>(10002, 0));

    cin >> n >> s;

    for (int i = 1; i <= n; i++) cin >> a.at(i);

    dp.at(0).at(0) = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j>=a.at(i) && dp.at(i-1).at(j-a.at(i))) dp.at(i).at(j) = true;
            else dp.at(i).at(j) =dp.at(i-1).at(j);
        }
    }

    if (dp.at(n).at(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}