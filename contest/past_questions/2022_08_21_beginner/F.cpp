#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define MOD 998244353

int n, d;
vector<vector<ll>> s1(1005, vector<ll>(1005, 0));
vector<vector<ll>> s2(1005, vector<ll>(1005, 0));

ll sum1(int j, int k) 
{
    if (j < 0 || k < 0) return 0;
    return s1.at(j).at(k);
}

ll sum2(int sj, int sk, int w)
{
    int tj = sj-w-1, tk = sk+w+1;
    if (sk < 0) {
        sj += sk;
        sk = 0;
    }
    if (sj < 0) return 0;
    ll res = s2.at(sj).at(sk);
    if (tj >= 0 && tk <= d) res -= s2.at(tj).at(tk);

    return res;
}

int main()
{
    cin >> n >> d;

    vector<int> p(105);
    vector<int> q(105);

    for (int i = 0; i < n; i++) cin >> p.at(i);
    for (int i = 0; i < n; i++) cin >> q.at(i);

    vector<vector<vector<ll>>> dp(105, vector<vector<ll>>(1005, vector<ll>(1005, 0)));

    dp.at(0).at(0).at(0) = 1;
    for (int i = 1; i <= n; i++) {

        swap(s1, dp.at(i-1));
        s2 = s1;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                s1.at(i+1).at(j+1) += s1.at(i).at(j);
                s1.at(i+1).at(j+1) %= MOD;
            }
        }
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                s2.at(i+1).at(j) += s2.at(i).at(j+1);
                s2.at(i+1).at(j) %= MOD;
            }
        }
        int w = abs(p.at(i-1) - q.at(i-1));

        for (int x = 0; x <= d; x++) {
            for (int y = 0; y <= d; y++) {
                // for (int r = -2000; r <= 2000; r++) {
                // int pd = abs(p.at(i-1) - r);
                // int qd = abs(q.at(i-1) - r);
                // if (x >= pd && y >= qd) dp.at(i).at(x).at(y) += dp.at(i-1).at(x-pd).at(y-qd);
                // dp.at(i).at(x).at(y) %= MOD; 
                // }
                dp.at(i).at(x).at(y) += sum1(x-1, y-w-1);
                dp.at(i).at(x).at(y) += sum1(x-w-1, y-1);
                dp.at(i).at(x).at(y) += sum2(x, y-w, w);
                dp.at(i).at(x).at(y) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {
            ans += dp.at(n).at(i).at(j);
            ans %= MOD;
        }
    }
    
    cout << (ans + MOD) % MOD << endl;

    return 0;
}