#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, ans = 0;
    vector<string> str(20);
    vector<int> dp(40000);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str.at(i);
    }

    for (int s = 1; s < (1<<n); s++) {
        int tmp = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (((s>>i) & 1) == 0) continue;
            for (int j = 0; j < (int)str.at(i).size(); j++) {
                m[str.at(i).at(j)]++;
            }
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (m[c] == k) tmp++;
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}