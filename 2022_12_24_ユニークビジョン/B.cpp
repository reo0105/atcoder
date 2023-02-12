#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    vector<int> a(100002);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a.at(i);

    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, b, c;
        cin >> x;
        if (x == 1) {
            cin >> b >> c;
            a.at(b) = c;
        } else {
            cin >> b;
            cout << a.at(b) << endl;
        }
    }
    return 0;
}