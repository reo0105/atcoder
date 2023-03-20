#include <bits/stdc++.h>
using namespace std;
#define INF 1L<<63
typedef long long ll;

int main()
{
    int n, m;
    vector<int> a(2005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<ll>> dp(2005, vector<ll>(2005, -INF));

    for (int i = 0; i <= n; i++) dp.at(i).at(0) = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i < j) continue;
            dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j));
            dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j-1) + j*a.at(i));
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = -INF;
    for (int i = 1; i <= n; i++) ans = max(ans, dp.at(i).at(m));

    cout << ans << endl;

    return 0;
}




#include <bits/stdc++.h>
using namespace std;
#define INF 1L<<63
typedef long long ll;

int main()
{
    int n, m;
    vector<int> a(2005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<ll>> dp(2005, vector<ll>(2005, -INF));

    dp.at(i).at(0) = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < j) continue;
            dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j));
            dp.at(i).at(j+1) = max(dp.at(i).at(j+1), dp.at(i-1).at(j) + (j+1)*a.at(i));
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = -INF;
    for (int i = 1; i <= n; i++) ans = max(ans, dp.at(i).at(m));

    cout << ans << endl;

    return 0;
}