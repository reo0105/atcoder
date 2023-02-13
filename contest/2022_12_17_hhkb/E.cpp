#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
i回目にkを食べたときの最大値？
*/


ll modpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }

    return res;
}

int main()
{  
    int n, m;
    vector<int> a(502);
    // vector<vector<vector<ll>>> dp(502, vector<vector<ll>>(502, vector<ll>(502, -1)));
    vector<vector<ll>> dp(502, vector<ll>(502, -1));
    vector<vector<set<int>>> eat(502, vector<set<int>>(502));

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a.at(i);

    dp.at(0).at(0) = 0;

    // for (int i = 0; i < n-1; i++) { // i回目
    //     for (int j = 0; j < n; j++) { // x;
    //         for (int k = 0; k < n; k++) {// y;
    //             if (j == k) break;
    //             if (dp.at(i).at(j).at(k) != -1) continue;
    //             dp.at(i+1).at(j).at(k) = max(dp.at(i+1).at(j).at(k), dp.at(i).at(pre_j).at(pre_k) + modpow(a.at(j), a.at(i), m) + modpow(a.at(i), a.at(j), m));
    //             dp.at(i+1).at(k).at(j) = max(dp.at(i+1).at(k).at(j), dp.at(i).at(pre_k).at(pre_j) + modpow(a.at(j), a.at(i), m) + modpow(a.at(i), a.at(j), m));
    //             pre_j = j; pre_k = k;
    //         }
    //     }
    // }


    int pre_j = 0, pre_k = 0;
    for (int i = 0; i < n; i++) { // 今回x
        for (int j = 0; j < n; j++) { // 今回y;
            for (int k = 0; k < n; k++) {// 前回食べた;
                if (i == j) break;
                if (eat.at(i).at(j).count(j) || eat.at(i).at(k).count(k)) continue;
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i).at(k) + modpow(a.at(j), a.at(k), m) + modpow(a.at(k), a.at(j), m));
                // dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(pre_j) + modpow(a.at(j), a.at(i), m) + modpow(a.at(i), a.at(j), m));
                eat.at(i).at(j).insert(k);
            }
        }
    }

    ll ans = -1;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            ans = max(ans, dp.at(j).at(k));
        }
    }

    cout << ans << endl;

    return 0;
}