#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int t = n;
    n--;

    int m = 0;
    while (n != 0) {
        m++;
        n /= 2;
    }

    cout << m << endl;

    vector<vector<int>> out(m);

    n = t;
    int x = pow(2, m) / 2;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if ((j>>k)&1) out[k].push_back(j);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << (int)out[i].size() << " ";
        for (int x : out[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    string ret;
    cin >> ret;

    int ans = 0;
    int two = 1;
    for (int i = 0; i < m; i++) {
        if (ret[i] == '1') ans += two;
        two *= 2;
    }

    if (ans == 0) ans = n;

    cout << ans << endl;
}