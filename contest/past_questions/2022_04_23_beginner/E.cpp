#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
<<<<<<< HEAD

int f(int k)
{
    int cnt = 0;
    while (k > 0) {
        k /= 10;
        cnt++;
    }

    return cnt+1;
}
=======
>>>>>>> efdf3965130a0de7b66a14ab5434de7f81498d8a

int main()
{
    int n, p;
<<<<<<< HEAD

    cin >> n >> p;

    vector<vector<ll>> dp(3005, vector<ll>(3005, 0));
    vector<vector<ll>> sum(3005, vector<ll>(3005, 0));

    for (int i = 1; i <= n; i++) {
        dp.at(i).at(f(i)) = 26;
    }

    vector<ll> ten = {0, 1, 10, 100, 1000, 3000};

    for (int i = 1; i <= n; i++) { //i文字目まで決めて
        for (int j = 1; j <= n; j++) { //圧縮した文字列がj文字
            // for (int w = 1; w <= n; w++) { //次のブロックの長さ
            //     int nj = j-f(w);
            //     if (nj <= 0) continue;
            //     if (i > w) dp.at(i).at(j) += dp.at(i-w).at(nj)*25;
            //     dp.at(i).at(j) %= p;
            // }

            for (int k = 1; k <= 4; k++) {
                int nj = j-k-1;
                if (nj <= 0) continue;
                int lb = ten.at(k), ub = ten.at(k+1);
                // if (i <= lb || i <= ub) continue;
                ub = min(ub, i);
                if (lb >= ub) continue;
                dp.at(i).at(j) += ((sum.at(i-lb).at(nj) - sum.at(i-ub).at(nj) + p) % p)*25;
                dp.at(i).at(j) %= p;
            }
            sum.at(i).at(j) = sum.at(i-1).at(j) + dp.at(i).at(j);
            sum.at(i).at(j) %= p;
        }
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += dp.at(n).at(i);
        ans %= p;
    }
    cout << ans << endl;

    return 0;
=======
    cin >> n >> p;

    vector<vector<ll>> dp(3005, vector<ll>(3005, 0));

    
>>>>>>> efdf3965130a0de7b66a14ab5434de7f81498d8a
}