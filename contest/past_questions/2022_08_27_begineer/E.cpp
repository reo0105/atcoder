#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n;
    double ans = 3.5;
    cin >> n;

    for (int i = 1; i < n; i++) {
        double t = 0;
        for (int j = 1; j <= 6; j++) {
            if (ans > j) t += ans / 6.0;
            else t += (double)j / 6.0;
        }
        ans = max(t, ans);
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}