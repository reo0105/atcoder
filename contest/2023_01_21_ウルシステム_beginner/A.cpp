#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, q, r, s;
    vector<int> a(105);

    cin >> n >> p >> q >> r >> s;

    for (int i = 1; i <= n; i++) cin >> a.at(i);

    for (int i = 1; i <= n; i++) {
        if (i == p) {
            for (int j = 0; j <= q-p; j++) {
                swap(a.at(i+j), a.at(r+j));
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << a.at(i) << " ";
    cout << endl;

    return 0;
}