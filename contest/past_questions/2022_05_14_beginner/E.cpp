#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<bool, ll> p;

int main()
{
    int n;
    vector<int> a(300005);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<vector<ll>>> dp0(300005, vector<vector<ll>>(2, vector<ll>(2, 1L<<58)));

    dp0.at(1).at(0).at(0) = 0;
    dp0.at(1).at(1).at(1) = a.at(1);
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 2; j++) { // A_iを払うか
            for (int k = 0; k < 2; k++) { // A_(i-1)を払ったか
                for (int l = 0; l < 2; l++) { // 最初を使ったか否か 
                    if (j == k && k == 0) continue;

                    if (j == 0) dp0.at(i).at(j).at(l) = min(dp0.at(i).at(j).at(l), dp0.at(i-1).at(k).at(l));
                    else dp0.at(i).at(j).at(l) = min(dp0.at(i).at(j).at(l), dp0.at(i-1).at(k).at(l) + a.at(i));
                }
            }
        }
    }

    // for (int j = 0; j < 2; j++) {
    //     for (int i = 1; i <= n; i++) {
    //         cout << dp0.at(i).at(j) << " "; 
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int j = 0; j < 2; j++) {
        // for (int i = 1; i <= n; i++) {
            // cout << dp1.at(i).at(j) << " "; 
        // }
        // cout << endl;
    // }

    ll ans = min(dp0.at(n).at(0).at(1), min(dp0.at(n).at(1).at(1), dp0.at(n).at(1).at(0)));
    cout << ans << endl;

    return 0;    
}