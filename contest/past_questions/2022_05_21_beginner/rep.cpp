#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a(200005);
    vector<int> cnt;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.at(x)++;
    }

    for (int i = 1; i <= 200000; i++) {
        if (a.at(i) != 0) cnt.push_back(a.at(i));
    }

    vector<vector<ll>> dp(200005, vector<ll>(5, 0));

    dp.at(0).at(0) = 1;

    for (int i = 0; i < (int)cnt.size(); i++) {
        for (int j = 0; j <= 3; j++) {
            if (i < j) break;

            dp.at(i+1).at(j) += dp.at(i).at(j);
            dp.at(i+1).at(j+1) += dp.at(i).at(j) * cnt.at(i);
        }
    }

    cout << dp.at((int)cnt.size()).at(3) << endl;

    return 0;
}