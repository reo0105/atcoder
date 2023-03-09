#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;
        vector<vector<int>> cnt(i, vector<int>(26, 0));
        for (int j = 0; j < n; j++) {
            cnt.at(j%i).at(s.at(j)-'a')++;
        }

        int num = 0;
        for (int j = 0; j < i; j++) {
            int maxi = -1;
            for (int k = 0; k < 26; k++) {
                maxi = max(maxi, cnt.at(j).at(k));
            }
            num += n/i - maxi;
        }

        if (num <= k) { ans = i; break; };
    }

    cout << ans << endl;

    return 0;
}