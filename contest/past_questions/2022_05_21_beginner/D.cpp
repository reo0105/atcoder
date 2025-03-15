#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    // vector<int> a(200005);
    map<int, int> cnt;

    cin >> n;
    for (int i = 1; i <= n; i++) {
       int a;
       cin >> a;
       cnt[a]++;
    }

    vector<int> c;
    for (auto p : cnt) c.push_back(p.second);

    vector<vector<long long>> dp(200005, vector<long long>(4, 0));

    dp.at(0).at(0) = 1;

    for (int i = 0; i < (int)c.size(); i++) {
        for (int j = 0; j < 4; j++) {
            dp.at(i+1).at(j) = dp.at(i).at(j);
            if (j >= 1) dp.at(i+1).at(j) += dp.at(i).at(j-1)*c.at(i);
        }
    }

    cout << dp.at((int)c.size()).at(3) << endl;

    return 0;
}