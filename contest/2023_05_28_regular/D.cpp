#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;

    cin >> n >> d;

    if (n*d > (n*(n-1) / 2)) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            cout << i << " " << (i-1+j)%n +1 << endl;
        }
    }

    return 0;
}