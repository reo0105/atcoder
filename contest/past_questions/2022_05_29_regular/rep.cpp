#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(65, vector<ll>(65, 0));
    dp.at(0).at(1) = 1;


    if (n >= 60) cout << 0 << endl;
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1)
        }
    }
    
    return 0;
}
