#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a < l) cout << l << endl;
        else if (l <= a && a <= r) cout << a << endl;
        else cout << r << endl;
    }

    return 0;
}