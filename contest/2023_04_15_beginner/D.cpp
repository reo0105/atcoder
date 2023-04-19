#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modpow(int top, ll ten, ll y)
{
    ll ret = top;
    while (y > 0) {
        if (y & 1) ret = ret * ten % MOD;
        ten = ten * ten % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    int q;
    cin >> q;

    ll ans = 1;
    int k = 1;
    ll rem = 0;
    int flag = 0;
    queue<int> que;
    que.push(1);

    for (int i = 0; i < q; i++) {
        int qu, x;
        cin >> qu;
        if (qu == 1) {
            cin >> x;
            ans *= 10;
            ans += x;
            k++;
            que.push(x);
            ans %= MOD;
        } else if (qu == 2) {
            int top = que.front();
            que.pop();
            ans -= modpow(top, 10, k-1);
            k--;
            ans = (ans + MOD) % MOD;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}