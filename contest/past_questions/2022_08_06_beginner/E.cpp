#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(200005);
    for (int i = 1; i <= n-1; i++) cin >> a.at(i);

    vector<mint> dp(200005, 0);
    vector<mint> sum(200005, 0);

    for (int i = n-1; i >= 1; i--) {
        sum.at(i) = sum.at(i+1) + dp.at(i+1);
        dp.at(i) = 1/mint(a.at(i)) * (sum.at(i) - sum.at(i+a.at(i))) + 1 + 1/mint(a.at(i));
    }

    cout << dp.at(1).val() << endl;
}