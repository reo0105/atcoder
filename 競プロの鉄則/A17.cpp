#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(100005), b(100005);
    vector<int> dp(100005, -1);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> a.at(i);
    }

    for (int i = 3; i <= n; i++) {
        cin >> b.at(i);
    }

    dp.at(1) = 0;
    dp.at(2) = a.at(2);

    for (int i = 3; i <= n; i++) {
        dp.at(i) = min(dp.at(i-1)+a.at(i), dp.at(i-2)+b.at(i));
    }

    int cnt = 0;
    vector<int> e(100005);  

    for (int i = n; i >= 2; i--) {
        if (dp.at(i)-a.at(i) == dp.at(i-1)) {
            e.at(cnt) = i;
            cnt++;
        } else {
            e.at(cnt) = i;
            cnt++;
            i--;
        }
    }

    e.at(cnt++) = 1;

    cout << cnt << endl;

    for (int i = cnt-1; i >= 0; i--) {
        cout << e.at(i) << " ";
    }
    cout << endl;

    return 0;
}