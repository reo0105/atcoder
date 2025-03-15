#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> p(2002), a(2002);
    vector<vector<int>> dp(2002, vector<int>(2002));

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p.at(i) >> a.at(i);

    for (int left = 1; left < n; left++) {
        for (int right = n-1; right >= left; right++) {
            if (p.at(i) <= left || right <= p.at(i)) dp.at(left).at(right) = dp.at(left-1).at(right) + a.at(left);
        }
    }
}