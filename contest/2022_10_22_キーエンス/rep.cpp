#include <bits/stdc++.h>
using namespace std;
#define INF 1e18

vector<int> x(20), y(20);//, p(10), q(10);
double dist(int i, int j, int cnt)
{
    double d = sqrt((double)(x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (double)(y.at(i) - y.at(j)) * (y.at(i) - y.at(j)));
    int two = 1;
    for (int i = 0; i < cnt; i++) two *= 2;
    return d / two;
}

int main()
{
    int n, m;
    vector<vector<double>> dp(20, vector<double>((1<<18)+5, INF));

    cin >> n >> m;
    x.at(0) = y.at(0) = 0;
    for (int i = 1; i <= n; i++) cin >> x.at(i) >> y.at(i);
    for (int i = n+1; i <= n+m; i++) cin >> x.at(i) >> y.at(i);

    dp.at(0).at(0) = 0;
    for (int s = 0; s < (1<<(n+m+1)); s++) {
        int cnt = 0;
        for (int i = n+1; i < n+m+1; i++) {
            if (s & (1<<i)) cnt++;
        }
        for (int i = 0; i < n+m+1; i++) {
            for (int j = 0; j < n+m+1; j++) {
                if (s != 0 && (s & (1<<i)) == 0) continue;
                if ((s & (1<<j)) == 0 && (i != j)) {
                    dp.at(j).at(s | (1<<j)) = min(dp.at(j).at(s | (1<<j)), dp.at(i).at(s) + dist(i, j, cnt));
                }
            }
        }
    }

    double ans = INF;
    int s = ((1<<(n+1)) -1);

    for (int i = 0; i < (1<<m); i++) {
        ans = min(ans, dp.at(0).at((i<<(n+1)) | s));
    }

    cout << fixed << setprecision(14) << ans << endl;

    return 0;
}