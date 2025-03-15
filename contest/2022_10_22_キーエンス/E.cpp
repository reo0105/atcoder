/*
2 次元平面上に N 個の街と M 個の宝箱があります。街 i は座標 (X_i, Y_i) に、宝箱 i は座標 (P_i, Q_i)にあります。

高橋君は原点を出発し、N 個の街全てを訪れたのち原点に戻る旅行をしようと考えています。
宝箱を訪れる必要はありませんが、宝箱の中にはそれぞれブースターが 1 つあり、ブースターを拾うごとに移動速度が 2 倍になります。

高橋君の最初の移動速度が単位時間あたり 1 であるとき、旅行にかかる時間の最小値を求めてください。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1L<<58

int count(int s, int m, int n) 
{
    int cnt = 0;
    // bitset<n+m> x(s);
    // for (int i = 0; i < m; i++) {
    //     if (x.test(i)) cnt++;
    // }

    for (int i = n+1; i < m+n+1; i++) {
        if ((s>>i) & 1) cnt++;
    }

    return cnt;
}

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n, m;
    vector<int> x(20), y(20);
    vector<vector<double>> dp(1<<18, vector<double>(20, INF));

    cin >> n >> m;
    for (int i = 1; i < n+1; i++) cin >> x.at(i) >> y.at(i);
    for (int i = n+1; i < n+m+1; i++) cin >> x.at(i) >> y.at(i);

    dp.at(0).at(0) = 0;
    //入力に原点が含まれてないことに気づいてんかった
    x.at(0) = 0;
    y.at(0) = 0;

    for (int s = 0; s < (1 << (n+m+1)); s++) {
        double coef = pow(0.5, count(s, m, n));
        for (int i = 0; i < n+m+1; i++) { //next
            for (int j = 0; j < n+m+1; j++) { //prev_newest
                if (s != 0 && ((s & (1 << j)) == 0)) continue;

                if (((s & (1 << i)) == 0) && (i != j)) {
                    dp.at(s | (1<<i)).at(i) = min(dp.at(s | (1<<i)).at(i), dp.at(s).at(j) + dist(x.at(i), y.at(i), x.at(j), y.at(j))*coef);
                    // cout << dist(x.at(i), y.at(i), x.at(j), y.at(j)) << " " << coef << endl;
                }
            }
        }
    }

    double ans = INF;
    int s = ((1<<(n+1)) -1);

    // cout << s << endl;

    for (int i = 0; i < (1<<m); i++) {
        ans = min(ans, dp.at((i<<(n+1)) | s).at(0));
        // cout << dp.at((i<<(n+1)) | s).at(0) << endl;
    }

    cout << fixed << setprecision(12) << ans << endl;

    // for(int i=0;i<n+m;i++)for(int s=(1<<n)-1;s<1<<(n+m);s+=1<<n)ans=min(ans,dp[s][i]+dist(x.at(i),y.at(i), 0.0, 0.0)*pow(0.5,count(s, m)));
    // cout << ans << endl;

    return 0;
}