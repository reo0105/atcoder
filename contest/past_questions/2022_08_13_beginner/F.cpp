#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2e18

int main()
{
    int h, w;
    vector<int> r(2005), c(2005);
    vector<string> a(2005);

    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> r.at(i);
    for (int i = 0; i < w; i++) cin >> c.at(i);
    for (int i = 0; i < h; i++) cin >> a.at(i);

    vector<vector<vector<ll>>> dp(2005, vector<vector<ll>>(2005, vector<ll>(4, INF)));

    for (int i = 0; i < 4; i++) {
        ll co = 0;
        if (i & 1) co += r.at(0); 
        if (i & 2) co += c.at(0); 
        dp.at(0).at(0).at(i) = co;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // 0:反転無し、1:行のみ反転、2:列のみ反転、3:両方反転
            for (int k = 0; k < 4; k++) {
                int x = a.at(i).at(j) - '0';
                if (k & 1) x ^= 1; //もともと行反転してるか
                if (k & 2) x ^= 1; //もともと列反転してるか

                if (i+1 < h) {
                    ll co = 0;
                    int nk = k&2; //列方向の反転は維持したまま
                    int y = a.at(i+1).at(j) - '0'; //下のタイルの色
                    if (k & 2) y ^= 1; //列方向に反転してるか
                    if (x != y) co += r.at(i+1), nk |= 1; //色が異なれば行を反転する必要あり
                    dp.at(i+1).at(j).at(nk) = min(dp.at(i+1).at(j).at(nk), dp.at(i).at(j).at(k)+co);
                }

                if (j+1 < w) {
                    ll co = 0;
                    int nk = k&1, y = a.at(i).at(j+1) - '0';
                    if (k & 1) y ^= 1;
                    if (x != y) co += c.at(j+1), nk |= 2;
                    dp.at(i).at(j+1).at(nk) = min(dp.at(i).at(j+1).at(nk), dp.at(i).at(j).at(k)+co);
                }
            }
            
            // dp.at(i).at(j).at(0) = min(min(dp.at(i-1).at(j).at(0), dp.at(i-1).at(j).at(1)), min(dp.at(i).at(j-1).at(0), dp.at(i).at(j-1).at(2)));
            // dp.at(i).at(j).at(1) = min(min(dp.at(i-1).at(j).at(0)+r.at(i), dp.at(i-1).at(j).at(1)+r.at(i)), min(dp.at(i).at(j-1).at(0)+r.at(i), dp.at(i).at(j-1).at(1)));
            // dp.at(i).at(j).at(2) = min(min(dp.at(i-1).at(j).at(0)+c.at(j), dp.at(i-1).at(j).at(2)), min(dp.at(i).at(j-1).at(0)+r.at(i), dp.at(i).at(j-1).at(1)));
            // dp.at(i).at(j).at(1) = min(min(dp.at(i-1).at(j).at(0)+r.at(i), dp.at(i-1).at(j).at(1)+r.at(i)), min(dp.at(i).at(j-1).at(0)+r.at(i), dp.at(i).at(j-1).at(1)));
        }
    }

    ll ans = INF;
    for (int i = 0; i < 4; i++) ans = min(ans, dp.at(h-1).at(w-1).at(i));

    cout << ans << endl;

    return 0;
}