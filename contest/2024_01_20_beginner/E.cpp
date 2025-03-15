#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m = 0;

    while ((1<<m) < n) m++;

    cout << m << endl;

    for (int i = 0; i < m; i++) {
        vector<int> a;
        for (int j = 0; j < n; j++) {
            if ((j>>i) & 1) a.push_back(j);
        }

        cout << a.size() << " ";
        for (int x : a) cout << x+1 << " ";
        cout << endl;
    }

    string s;
    cin >> s;

    int ans = 1;
    int two = 1;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') {
            ans += two;
        }
        two <<= 1;
    } 

    cout << ans << endl;

    return 0;
}