#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(400);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    // int from = 0, now = 0, to = 360;

    // for (int i = 0; i < n; i++) {
    //     now += a.at(i);
    //     if (now >= 360) now -= 360;
    //     if (from < now && now < to) {
    //         if ((now - from) > (to - now)) to = now;
    //         else from = now;
    //     }
    // }

    // cout << to - from << endl;

    vector<int> cut;
    int now = 0;

    cut.push_back(0);
    for (int i = 0; i < n; i++) {
        now += a.at(i);
        if (now >= 360) now -= 360;
        cut.push_back(now);
    }

    sort(cut.begin(), cut.end());
    cut.push_back(360);

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (cut.at(i+1)-cut.at(i) > ans) ans = cut.at(i+1)-cut.at(i);
    }

    cout << ans << endl;

    return 0;
}