#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    vector<int> a(100002), left(100002, 0), right(100002, 0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a.at(i);

    cin >> d;

    for (int i = 1; i <= n; i++) {
        left.at(i) = max(left.at(i-1), a.at(i));
    }

    for (int i = n; i >= 1; i--) {
        right.at(i) = max(right.at(i+1), a.at(i));
    }

    for (int i = 0; i < d; i++) {
        int l, r;
        cin >> l >> r;
        cout << max(left.at(l-1), right.at(r+1)) << endl;
    }

    return 0;
}