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

vector<bool> seen(200005, false);
vector<vector<int>> p(200005);

void dfs(int from)
{
    seen.at(from) = true;
    
    for (int u : p.at(from)) {
        if (seen.at(u)) continue;

        dfs(u);
    }

    return;
}


int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        p.at(a).push_back(i);
        p.at(i).push_back(a);
    }


    int cnt = 0;
    for (int i = 1; i<= n; i++) {
        if (!seen.at(i)) {
            dfs(i);
            cnt++;
        }
    }

    ll ans = modpow(m, n);
    ans -= modpow(m, cnt);
    ans += MOD;
    ans %= MOD;
    ans *= modpow(2, MOD-2);
    ans %= MOD;

    // cout << cnt << endl;
    cout << ans << endl;

    return 0;
}