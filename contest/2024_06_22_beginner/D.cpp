#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main()
{
    int n, k;
    cin >> n >> k;

    string S;
    cin >> S;

    vector<map<string, ll>> dp(n+5);

    dp[0][""] = 1;

    for (int i = 0; i < n; i++) {
        for (auto [str, cnt] : dp[i]) {
            for (char c = 'A'; c <= 'B'; c++) {
                if (S[i] != '?' && S[i] != c) continue;
                string new_str = str + c;
                if ((int)new_str.size() > k) new_str.erase(new_str.begin());
                string istr(new_str.rbegin(), new_str.rend());
                
                if ((int)new_str.size() == k && new_str == istr) continue;

                dp[i+1][new_str] += dp[i][str];
                dp[i+1][new_str] %= MOD;

            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1<<k); i++) {
        string str;
        for (int j = 0; j < k; j++) {
            if ((i>>j)&1) str.push_back('A');
            else str.push_back('B');
        }
        ans += dp[n][str];
        ans %= MOD;
    }
    cout << ans << endl;
}