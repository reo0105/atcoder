#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, a;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == x) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}