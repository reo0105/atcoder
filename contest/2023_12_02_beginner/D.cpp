#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<string> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];


    vector<vector<int>> cnt(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i+1][j+1] = cnt[i][j+1] + cnt[i+1][j] - cnt[i][j];
            if (p[i][j] == 'B') cnt[i+1][j+1]++;
        }
    }

    auto f = [&](int c, int d) {
        ll res = cnt[c%n][d%n];
        res += cnt[n][n]*(ll)(c/n)*(d/n);
        res += cnt[n][d%n]*(ll)(c/n);
        res += cnt[c%n][n]*(ll)(d/n);
        return res;
    };

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c++; d++;
        ll ans = f(c, d) - f(c, b) - f(a, d) + f(a, b);

        cout << ans << endl;
    }

    return 0;
}