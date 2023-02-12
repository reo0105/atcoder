#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
typedef long long ll;

vector<mint> fac(100005);
vector<mint> invf(100005);

// void factorial()
// {
//     fac.at(0) = fac.at(1) = mint(1);
//     invf.at(0) = invf.at(1) = mint(1);

//     for (int i = 2; i < 100000; i++) {
//         fac.at(i) = fac.at(i-1) * i;
//         invf.at(i) = invf.at(i-1) / i;
//     }

//     return ;
// }

// int nCr(int n, int r)
// {
//     return fac.at(n) / invf.at(r) / invf.at(n-r);
// }

int main()
{
    int n, k;
    vector<ll> a(100005);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    ll sum = 0;
    for (int i = 1; i < n; i++) sum += a.at(i);

    a.at(0) -= (k + sum);
    if (a.at(0) < 0) {
        cout << 0 << endl;
    } else {
        mint ans = mint(1);
        // factorial();
        mint kinv = mint(1);

        for (int i = 2; i < k; i++) kinv /= i;

        for (int i = 0; i < n; i++) {
            mint mul = mint(1);
            for (int j = 1; j < k; j++) {
                mul *= a.at(i) + j;
            }
            mul *= kinv;
            ans *= mul;
        }

        cout << ans.val() << endl;
    }
}