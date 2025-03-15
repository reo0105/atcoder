#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;

    map<ll, double> memo;
    auto f = [&](auto f, ll n) -> double {
        if (n == 0) return 0;
        if (memo.count(n)) return memo[n];
        double res = f(f, n/a) + x;
        double dice = 0;
        for (int i = 2; i <= 6; i++) {
            dice += f(f, n/i);
        }
        dice /= 5;
        dice += y*6/5.0;
        res = min(res, dice);
        memo[n] = res;
        return res;
    };

    cout << setprecision(12) << f(f, n) << endl;

    return 0;
}