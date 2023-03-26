#include <bits/stdc++.h>
using namespace std;
#define INF 1e10

int main()
{
    int n;
    vector<int> a(100005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    {
    double l = 1.0, r = INF;
    while (r - l > 1e-4) {
        double mean = (l + r) / 2.0;
        vector<double> b(100005);

        for (int i = 0; i < n; i++) b.at(i) = a.at(i) - mean;

        vector<vector<double>> dp(2, vector<double>(100005, -INF));

        dp.at(0).at(0) = 0;
        dp.at(1).at(0) = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) { //now
                for (int k = 0; k < 2; k++) { //pre
                    if (j == 0 && k == 0) continue;

                    if (j == 0) dp.at(0).at(i+1) = dp.at(1).at(i);
                    if (j == 1) {
                        dp.at(1).at(i+1) = max(dp.at(1).at(i+1), dp.at(k).at(i) + b.at(i)); //overflow??かなんかの関係でバグる。普通にkなしで書けば行ける
                        // cout << j << " " << k << endl;
                    }
                }
            }
        }

        double maxi = max(dp.at(0).at(n), dp.at(1).at(n));

        if (maxi >= 0) l = mean;
        else r = mean;
    }
    cout << fixed << setprecision(10) << l << endl;
    }

    int l = 1, r = INF;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        vector<int> b(100005);

        for (int i = 0; i < n; i++) b.at(i) = (a.at(i) < mid) ? -1 : 1;

        vector<vector<int>> dp(2, vector<int>(100005, -INF));

        dp.at(0).at(0) = 0;
        dp.at(1).at(0) = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) { //now
                // for (int k = 0; k < 2; k++) { //pre
                    // if (j == 0 && k == 0) continue;

                if (j == 0) dp.at(0).at(i+1) = dp.at(1).at(i);
                if (j == 1) dp.at(1).at(i+1) = max(dp.at(0).at(i) + b.at(i), dp.at(1).at(i) + b.at(i));
                // }
            }
        }

        int maxi = max(dp.at(0).at(n), dp.at(1).at(n));
        
        if (maxi > 0) l = mid;
        else r = mid;
        // cout << l << " " << r << " " << maxi << endl;
    }

    cout << l << endl;

    return 0;
}