#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a(5005);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<ll>> dp(5005, vector<ll>(5005, 0)); //i日目まで決めて直前の休日がj日前
    vector<ll> b(5005, 0);

    for (int w = 1; w <= n; w++) {
        for (int i = 1; i < w; i++) {
            int j = w-i;
            b.at(w) += a.at(min(i, j));
        }
    }


    // for (int w = 1; w <= n; w++) {
    //     cout << b.at(w) << endl;
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // dp.at(i).at(j) = dp.at(i-j).at(j-1) - b.at(j-1) + b.at(j);
            // dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            dp.at(i).at(j) = dp.at(i-1).at(j-1); //　すべて平日と仮定してjを増やす
            // dp[i][0]=max(dp[i][0],dp[i-1][j-1]+b[j]);
            dp.at(i).at(0) = max(dp.at(i).at(0), dp.at(i-1).at(j-1) + b.at(j)); // 全て休日と仮定してその日までの生産量を求める
        }
    }

    ll ans = 0;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp.at(n).at(i)+b.at(i));
    }
    
    cout << ans << endl;

    return 0;
}

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n+1);
//     for (int i = 1; i <= n; i++) cin >> a.at(i);

//     vector<ll> b(n+1);
//     for (int w = 1; w <= n; w++) {
//         for (int i = 1; i < w; i++) {
//             int j = w-i;
//             b.at(w) += a.at(min(i, j));
//         }
//     }

//     vector<ll> dp(n+1); //最後の休日がi日目

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j < i; j++) {
//             dp.at(i) = max(dp.at(i), dp.at(j)+b.at(i-j));
//         }
//     }

//     cout << dp.at(n) << endl; 
// }