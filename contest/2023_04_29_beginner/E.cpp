#include <bits/stdc++.h>
using namespace std;
#typedef long long ll;
#define MOD 998244353

ll modinv(ll a)
{
    ll ret = 1, y = MOD - 2;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{

    ll n;
    cin >> n;

    int two = 0, three = 0, five = 0;

    while (n % 2 == 0) {
        two++;
        n /= 2;
    }
    while (n % 3 == 0) {
        three++;
        n /= 3;
    }
    while (n % 5 == 0) {
        five++;
        n /= 5;
    }

    if (n != 1) {
        cout << 0 << endl;
        return 0;
    }

    

    

    return 0;
}