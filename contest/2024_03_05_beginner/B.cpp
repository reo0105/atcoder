#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            if (t == 1) cout << j << " ";
        }
        cout << endl;
    }
}