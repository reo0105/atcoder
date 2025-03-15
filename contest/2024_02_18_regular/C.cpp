#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    string s;

    cin >> n >> s;
    s.push_back(s[n-1]);

    int flag = (s[0] == 'A') ? 1 : -1;

    vector<int> sum(n+5, 0);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1] - 1;
    }

    int minus = 0;

    for (int i = 1; i <= n; i++) {
        // cout << sum[i] << " ";
        if (sum[i] <= -2 || 2 <= sum[i]) minus = 1;
    }

    // cout << minus << endl;

    int ans = 1;
    int first = 1;
    if (flag == 1) {
        for (int i = 1; i < n; i++) {
            if (sum[i] == 0 && s[i+1] == 'B') ans++;
            else if (sum[i] == -1 && s[i+1] == 'B') ans++;
            else if (sum[i] == 1 && s[i+1] == 'B') ans++;

            if (first && ans == 2) {
                first = 0;
                if (minus) ans--;
            }
        }
    } else {
        for (int i = 1; i < n; i++) {
            if (sum[i] == -1 && s[i+1] == 'A') ans++;
            else if (sum[i] == 0 && s[i+1] == 'A')  ans++;
            else if (sum[i] == 1 && s[i+1] == 'A') ans++;
            if (first && ans == 2) {
                first = 0;
                if (minus) ans--;
            }
        }

    }

    cout << ans << endl;

    return 0;
}