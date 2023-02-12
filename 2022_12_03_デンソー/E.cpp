#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
typedef long long ll;


int main()
{
    int n, p;
    mint two, one;
    vector<mint> dp(200002, mint(0));
    // mint m_inv = mint(1) / m;
    
    cin >> n >> p;
    two = (mint)p / 100;
    one = 1 - two;

    cout << one.val() <<  " " << two.val() << endl;

    dp.at(0) = mint(0); dp.at(1) = mint(1);
    
    for (int i = 2; i <= n; i++) {
        dp.at(i) = dp.at(i-2) * two + dp.at(i-1) * one + 1;
    }

    cout << dp.at(n).val() << endl;

    return 0;
}