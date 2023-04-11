#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, p;
    cin >> n >> p;

    vector<vector<vector<ll>>> dp(3005, vector<vector<ll>>(3005, vector<ll>(2, 0)));

    dp.at(1).at(0).at(0) = 1;
    dp.at(1).at(1).at(1) = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp.at(i+1).at(j).at(0) += dp.at(i).at(j).at(0) + dp.at(i).at(j).at(1);
            dp.at(i+1).at(j+1).at(0) += dp.at(i).at(j).at(0);
            dp.at(i+1).at(j+1).at(1) += dp.at(i).at(j).at(1);
            dp.at(i+1).at(j+1).at(0) += dp.at(i).at(j).at(0)*2;
            dp.at(i+1).at(j+2).at(1) += dp.at(i).at(j).at(0)*2;
            dp.at(i+1).at(j).at(0) %= p;
            dp.at(i+1).at(j+1).at(0) %= p;
            dp.at(i+1).at(j+1).at(1) %= p;
            dp.at(i+1).at(j+2).at(1) %= p;
        }
    }

    for (int i = 1; i < n; i++) cout << dp.at(n).at(i).at(0) << " ";
    cout << endl;

    return 0;
}