#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll l, r;
    cin >> l >> r;

    vector<pll> ans;

    auto f = [&](auto f, ll li, ll ri) -> void {
        if (l <= li && ri <= r) {
            ans.emplace_back(li, ri);
            return;
        }
        ll c = (li+ri)/2;
        if (l < c) f(f, li, c);
        if (c < r) f(f, c, ri);
    };
    f(f, 0, 1LL<<60);

    cout << ans.size() << endl;
    for (auto [l, r] : ans) cout << l << " " << r << endl;

    return 0;
}