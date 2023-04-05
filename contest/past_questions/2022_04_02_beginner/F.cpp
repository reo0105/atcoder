#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modpow(ll a, ll y)
{
    ll ret = 1;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    int n, l;
    vector<string> str(20);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> str.at(i);
    }

    ll ans = 0;

    for (int s = 1; s < (1<<n); s++) {
        int cnt = 0;
        set<int> st;
        for (int i = 0; i < n; i++) {
            if ((s>>i)&1) {
                cnt++;
                st.insert(i);
            }
        }

        // cout << cnt << endl;
        map<char, int> alpha;
        while(st.size()) {
            int mini = *begin(st);
            st.erase(mini);

            for (int i = 0; i < (int)str.at(mini).size(); i++) {
                alpha[str.at(mini).at(i)]++;
            }

            int c = 0;
            for (auto p : alpha) {
                if (p.second == cnt) c++;
            }

            int sign = (cnt % 2) ? 1 : -1;
            ans += modpow(c, l) * sign;
            ans = (ans + MOD) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}