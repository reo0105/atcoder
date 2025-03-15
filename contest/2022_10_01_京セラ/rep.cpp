#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector<vector<int>> dp(105, vector<int>(10005, -1));
    vector<int> a(105), b(105);
    for (int i = 1; i <= n; i++) cin >> a.at(i) >> b.at(i);

    dp.at(1).at(a.at(1)) = 0;
    dp.at(1).at(b.at(1)) = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if(j >= a.at(i) && dp.at(i-1).at(j-a.at(i)) != -1) dp.at(i).at(j) = 0;
            if(j >= b.at(i) && dp.at(i-1).at(j-b.at(i)) != -1) dp.at(i).at(j) = 1;
        }
    }

    if (dp.at(n).at(s) == -1) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int now = s;
        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            if (!dp.at(i).at(now)) {
                ans.push_back(0);
                now -= a.at(i);
            } else {
                ans.push_back(1);
                now -= b.at(i);
            }
        }

        reverse(ans.begin(), ans.end());

        for (int x : ans) {
            if (x) cout << "T";
            else cout << "H";
        }
        cout << endl;
    }

    return 0;
}