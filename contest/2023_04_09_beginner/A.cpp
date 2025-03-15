#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    int t0, t1;
    cin >> t0;
    for (int i = 1; i < n; i++) {
        cin >> t1;
        if (t1 - t0 <= d) {
            cout << t1 << endl;
            return 0;
        }
        t0 = t1;
    }

    cout << -1 << endl;

    return 0;
}