#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> p(2002), a(2002);
    vector<vector<int>> dp(2002, vector<int>(2002, 0));

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> p.at(i) >> a.at(i);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            dp.at(i).at(j) = 
        }
    }

    return 0;
}