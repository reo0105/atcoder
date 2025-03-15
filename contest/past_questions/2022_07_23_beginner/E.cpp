#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> d(2);
    d[1] = -1;

    for (int i = 1; i <= n; i++) {
        int t, a;
        cin >> t >> a;
        for (int j = 0; j < 2; j++) {
            if (t == 1) d[j] &= a;
            else if (t == 2) d[j] |= a;
            else d[j] ^= a;
        }
        c = (c&d[1]) | (~c&d[0]);
        cout << c << endl;
    } 

    return 0;
}