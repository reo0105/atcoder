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
    int n;
    string s;
    cin >> n >> s;

    vector<int> necess;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == '.') necess.push_back(i);
    }

    vector<int> prim;
    for (int i = 1; i*i <= n; i++) {
        if (n % i != 0) continue;

        prim.push_back(i);
        if (i != 1 && i != n/i)prim.push_back(n/i);
    }

    sort(prim.begin(), prim.end());

    ll ans = 0;
    vector<ll> b(200005);
    vector<vector<int>> ds(200005);
    for (int p : prim) {
        set<int> fix;

        for (int x : necess) {
            // cout << x << " ";
            fix.insert(x % p);
        }
        // cout << endl;

        // cout << p << " : ";
        // for (int x : fix) cout << x << " ";
        // cout << endl;

        int cnt = p - (int)fix.size();

        ll tmp = modpow(2, cnt);

        for (int d : ds.at(p)) {
            tmp -= b.at(d);
            tmp = (tmp + MOD) % MOD;
        }
        b.at(p) = tmp;

        ans += tmp;
        ans %= MOD;

        for (int i = p*2; i < n; i += p) ds.at(i).push_back(p);
    }

    cout << ans << endl;

    return 0;
}