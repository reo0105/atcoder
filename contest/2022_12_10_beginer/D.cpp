#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
n個からk個選ぶ組み合わせと下は基本dpかbit全探索
i: i番目までを考えたとき
j: j個選んで
k: kになるdp[i][j][k]
*/

int main()
{
    int n, d, k;
    vector<int> a(102); 
    vector<vector<vector<ll>>> dp(102, vector<vector<ll>>(102, vector<ll>(102, -1)));

    cin >> n >> k >> d;

    for (int i = 0; i < n; i++) cin >> a.at(i);

    // for (int i = 0; i < n; i++) 
    dp.at(0).at(0).at(0) = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int ck = 0; ck < d; ck++) {
                // if (i < j) continue;
                if (dp.at(i).at(j).at(ck) == -1) continue; // これなんでいるんだろ <-- たぶん－1になるのはありえないときdp.at(3).at(0).at(1)みたいな感じ　だから考慮したらいけない？　
                dp.at(i+1).at(j).at(ck) = max(dp.at(i+1).at(j).at(ck), dp.at(i).at(j).at(ck));
                dp.at(i+1).at(j+1).at((ck+a.at(i))%d) = max(dp.at(i+1).at(j+1).at((ck+a.at(i))%d), dp.at(i).at(j).at(ck) + a.at(i));
            }
        }
    }

    cout << dp.at(n).at(k).at(0) << endl;

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         for (int ck = 0; ck < d; ck++) {
    //             cout << dp.at(i).at(j).at(ck) << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}