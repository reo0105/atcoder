#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modinv(ll i)
{
    ll ret = 1;
    ll y = MOD - 2;
    
    while (y > 0) {
        if ((y>>1) & 1) ret = ret * i % MOD;
        i = i * i % MOD;
        y >>= 1;
    }

    return ret;
}


int main()
{
    string s;
    map<int, int> mp;

    cin >> s;
    int n = (int)s.size();

    vector<ll> fac(5005);
    vector<ll> finv(5005);

    fac.at(0) = fac.at(1) = 1;
    finv.at(0) = finv.at(1) = 1;
    for (int i = 2; i <= n; i++) {
        fac.at(i) = fac.at(i-1) * i % MOD;
        finv.at(i) = finv.at(i-1) * modinv(i) % MOD;
    }

    for (int i = 0; i < n; i++) mp[s.at(i)-'a'+1]++;

    vector<vector<ll>> dp(30, vector<ll>(5005, 0));

    dp.at(0).at(0) = 1;

    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= n; j++) {
            dp.at(i).at(j) = dp.at(i-1).at(j)
        }
    }

}