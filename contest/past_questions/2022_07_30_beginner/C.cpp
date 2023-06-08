#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

/*
小さい数字に大きい数字をかけてもいいことない
小さい順にかけるのが最適？

するとＡは奇数列、Ｂは偶数列になる。

xをn個yをn個並べる順列に等しい。　違うのか？？

ペアを固定する。nペア
その並びがn!、各ペアについてどちらが先かで2^N

このときに左に決めたものは右に決めたものよりも当然前にあるはず
https://ja.wikipedia.org/wiki/%E3%82%AB%E3%82%BF%E3%83%A9%E3%83%B3%E6%95%B0

*/

ll modinv(ll a)
{
    ll ret = 1;
    ll y = MOD - 2;

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
    cin >> n;

    ll pn = 1, pn1inv = 1, pninv = 1, two = 1;

    for (int i = 1; i <= n; i++) {
        pn1inv *= modinv(i);
        pninv *= modinv(i);
        pn *= i;
        two *= 2;
        pn1inv %= MOD;
        pninv %= MOD;
        pn %= MOD;
        two %= MOD;
    }

    pn1inv *= modinv(n+1);
    pn1inv %= MOD;

    ll p2n = 1;
    for (int i = 1; i <= 2*n; i++) {
        p2n *= i;
        p2n %= MOD;
    }

    ll ans = two * p2n % MOD;
    ans = ans * pn1inv % MOD;
    ans = ans * pninv % MOD;
    ans = ans * pn % MOD;

    cout << ans << endl;

    return 0;
}