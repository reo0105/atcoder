#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;

        if (n/2 > a) {

            int p = (n-a) * ((n+1) / 2);

            if (p >= b) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        }

        n -= a;

        if (n < 0) {
            cout << "No" << endl;
            continue;
        }

        if (n*n >= b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}