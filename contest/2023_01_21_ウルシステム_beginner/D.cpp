#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    vector<int> a(55), b(55);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    vector<vector<bool>> dp(55, vector<bool>(10005, false));
    vector<vector<int>> cnt(55, vector<int>(10005, 0));

    dp.at(0).at(0) = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp.at(i-1).at(j)) {
                dp.at(i).at(j) = dp.at(i-1).at(j);
                cnt.at(i).at(j) = 0;
                continue;
            }
            if (j >= a.at(i) && dp.at(i).at(j-a.at(i)) && cnt.at(i).at(j-a.at(i)) < b.at(i)) {
                dp.at(i).at(j) = true;
                cnt.at(i).at(j) = cnt.at(i).at(j-a.at(i)) + 1;
            }
        }
    }

    if (dp.at(n).at(x)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}