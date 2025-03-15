#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, k;
    vector<int> a(200005), b(200005);
    vector<vector<bool>> dp(200005, vector<bool>(2, false));

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a.at(i);
    for (int i = 1; i <= n; i++) cin >> b.at(i);

    int flag = 1;

    dp.at(0).at(0) = true;
    dp.at(0).at(1) = true;

    for (int i = 1; i <= n-1; i++) {
        if ((abs(a.at(i) - a.at(i+1)) <= k)) {
            dp.at(i).at(0) = dp.at(i-1).at(0);
        }
        if ((abs(a.at(i) - b.at(i+1)) <= k)) {
            dp.at(i).at(1) = dp.at(i-1).at(0);
        }
        if ((abs(b.at(i) - a.at(i+1)) <= k)) {
            dp.at(i).at(0) = dp.at(i-1).at(1) | dp.at(i).at(0);
        }
        if ((abs(b.at(i) - b.at(i+1)) <= k)) {
            dp.at(i).at(1) = dp.at(i-1).at(1) | dp.at(i).at(1);
        }
    }

    bool ans = false;
    ans = dp.at(n-1).at(0) | dp.at(n-1).at(1);

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}