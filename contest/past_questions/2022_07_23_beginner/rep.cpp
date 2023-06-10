#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, c;
    cin >> n >> c;

    vector<int> d(2, 0);
    d.at(1) = -1;

    for (int i = 0; i < n; i ++) {
        int t, a;
        cin >> t >> a;
        if (t == 1) {
            d.at(0) &= a;
            d.at(1) &= a;
        } else if (t == 2) {
            d.at(0) |= a;
            d.at(1) |= a;
        } else {
            d.at(0) ^= a;
            d.at(1) ^= a;
        }

        c = (~c&d.at(0)) | (c&d.at(1));
        cout << c << endl;
    }

    return 0; 
}