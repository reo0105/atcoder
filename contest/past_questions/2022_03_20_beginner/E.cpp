#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

// int main()
// {
//     int n, m, k, s, t, x;
//     cin >> n >> m >> k >> s >> t >> x;

//     vector<vector<vector<int>>> dp(2005, vector<vector<int>>(2005, vector<int>(2, 0))); //i回目に頂点jにいる　（xをk回通った）
//     vector<vector<int>> G(2005);

//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         G.at(u).push_back(v);
//         G.at(v).push_back(u);
//     }

//     dp.at(0).at(s).at(0) = 1;

//     for (int i = 1; i <= k; i++) { //i回目の移動
//         for (int j = 1; j <= n; j++) { // jにいる
//             if (j == x) {
//                 for (int adj : G.at(j)) {
//                     dp.at(i).at(j).at(0) += dp.at(i-1).at(adj).at(1);
//                     dp.at(i).at(j).at(1) += dp.at(i-1).at(adj).at(0);
//                     dp.at(i).at(j).at(0) %= MOD;
//                     dp.at(i).at(j).at(1) %= MOD;
//                 }
//             } else {
//                 for (int adj : G.at(j)) {
//                     dp.at(i).at(j).at(0) += dp.at(i-1).at(adj).at(0);
//                     dp.at(i).at(j).at(1) += dp.at(i-1).at(adj).at(1);
//                     dp.at(i).at(j).at(0) %= MOD;
//                     dp.at(i).at(j).at(1) %= MOD;
//                 }
//             }
//         }
//     }
    
//     cout << dp.at(k).at(t).at(0) << endl;

//     return 0;
// }

typedef pair<int, int> p;

int main()
{
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;

    vector<vector<vector<int>>> dp(2005, vector<vector<int>>(2005, vector<int>(2, 0))); //i回目に頂点jにいる　（xをk回通った）
    vector<p> G;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.push_back(make_pair(u, v));
    }

    dp.at(0).at(s).at(0) = 1;

    for (int i = 1; i <= k; i++) { //i回目の移動
        for (p edge : G) {
            int u = edge.first;
            int v = edge.second;
            for (int j = 0; j <= 1; j++) {
                dp.at(i).at(u).at((u == x) ^ j) += dp.at(i-1).at(v).at(j);
                dp.at(i).at(v).at((v == x) ^ j) += dp.at(i-1).at(u).at(j);
                dp.at(i).at(u).at((u == x) ^ j) %= MOD;
                dp.at(i).at(v).at((v == x) ^ j) %= MOD;
            }
        }
    }
    
    cout << dp.at(k).at(t).at(0) << endl;

    return 0;
}
