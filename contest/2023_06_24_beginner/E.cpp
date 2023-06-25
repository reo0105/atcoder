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
    int n, m;

    cin >> n >> m;

    ll ans = 
    for (int i = 1; i <= n; i++) {

    }

    return 0;
}