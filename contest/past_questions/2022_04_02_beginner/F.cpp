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
    ll n, l;
    cin >> n >> l;

    ll ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int cnt;
        string s;
        cin >> s;
        int sz = (int)s.size();
        set<char> st;
        for (int j = 0; j < sz; j++) {
            st.insert(s.at(j));
            mp[s.at(j)]++;
        }
        cnt = (int)st.size();

        int new_letter = 0;
        for (int j = 0; j <= 26; j++) {
            char c = 'a' + j;
            if (st.count(c) && mp[c] == 1) {
                new_letter++;
            }
        }

        cout << new_letter << endl;

        ll t = 1;
        t *= new_letter;
        t %= MOD;
        t *= modpow(cnt, l-1);
        t %= MOD;
        ans += t;
    }

    cout << ans << endl;

    return 0;
}