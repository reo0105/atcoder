#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main() {
    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;

    for (int i = 0; i < n-1; i++) {
        if (s[i] != '1' && s[i+1] != '1') {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = n-1; i > 0; i--) {
        int c = s[i] - '0';
        ans++;
        ans += ans*(c-1) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}