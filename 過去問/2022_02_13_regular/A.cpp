#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int modpow(ll a, ll x)
{
    ll res = 1;

    while (x > 0) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }

    return res;
}

int main()
{
    ll four = 0, three = 0, tow = 0;
    ll n;

    cin >> n;
    set<ll> s;
    map<ll, ll> mp;

    s.insert(n);
    mp[n] = 1;

    while(1) {
        ll x = *rbegin(s);
        s.erase(x);
        if (x <= 4) break;

        ll cnt = mp[x];
        
        ll nx0 = x / 2;
        ll nx1 = (x+1) / 2;
        s.insert(nx0);
        s.insert(nx1);

        if (mp.count(nx0)) mp.at(nx0) += cnt;
        else mp[nx0] = cnt;

        if (mp.count(nx1)) mp.at(nx1) += cnt;
        else mp[nx1] = cnt;
    }

    ll ans = 1;

    for (ll i = 2; i <= 4; i++) {
        if (mp.count(i)) {
            // cout << i << " " << mp.at(i) << endl;
            // mp.at(i) %= MOD;
            ll t = modpow(i, mp.at(i));
            // ll t = pow(i, mp.at(i));
            t %= MOD;
            // cout << t << endl;
            ans = (ans * t) % MOD;
        }
    }

    cout << ans << endl; 

    return 0; 

}