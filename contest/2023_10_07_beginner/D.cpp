#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    unordered_map<ll, ll> mp;
    unordered_set<ll> st;
    for (int i = 0; i < n; i++) {
        int s, c;
        cin >> s >> c;
        mp[s] = c;
        st.insert(s);
    }

    while (st.size()) {
        ll mini = *begin(st);

        ll cnt = mp[mini];
        ll num = cnt / 2;
        mp[mini] -= num * 2;

        mp[mini*2] += num;

        st.erase(mini);
        if (num != 0) st.insert(mini*2);
    }

    ll ans = 0;
    for (auto [k, v] : mp) {
        ans += v;
    }
    cout << ans << endl;

    return 0;
}