#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(vector<int> xs) {
    int n = (int)xs.size();
    sort(xs.begin(), xs.end());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll co = i - (n-i-1);
        res += co * xs[i];
    }

    return res/2;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> xs(2), ys(2);

    for (int i = 0; i < n; i++) {
        int X, Y;
        cin >> X >> Y;
        int x = X + Y;
        int y = X - Y;
        xs[x%2].push_back(x);
        ys[x%2].push_back(y);
    }

    ll ans = 0;
    for (int i = 0; i < 2; i++) {
        ans += f(xs[i]) + f(ys[i]);
    }
    cout << ans << endl;

    return 0;
}