#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> num(300005);
    vector<int> a(35, 0);

    cin >> n;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += x;
        num.at(i) = x;
        for (int j = 0; j < 30; j++) {
            if (x & 1) a.at(j) += 1;
            x >>= 1; 
        }
    }

    // for (int j = 0; j < 30; j++) {
    //     cout << a.at(j) << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
        int choose = num.at(i);
        ll tmp = 0, two = 1;
        for (int j = 0; j < 30; j++) {
            if (choose & 1) {
                tmp += two * (n-a.at(j));
            } else {
                tmp += two * a.at(j);
            }
            two *= 2;
            choose >>= 1;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}