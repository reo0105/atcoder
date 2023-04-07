#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n, x, y;
    vector<int> a(200005);

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    int posx = -1, posy = -1;
    int b = 0;
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a.at(i) == x) posx = i;
        if (a.at(i) == y) posy = i;
        if (a.at(i) < y || x < a.at(i)) b = i;
        // cout << i << " " << posx << " " << posy << " " << b << endl;
        ans += max(0, min(posx, posy) - b);
    }

    cout << ans << endl;

    return 0;
}