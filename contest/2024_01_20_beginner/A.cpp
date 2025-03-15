#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        int t, u;
        cin >> t >> u;
        x += t;
        y += u;
    }

    if (x > y) cout << "Takahashi" << endl;
    else if (x < y) cout << "Aoki" << endl;
    else cout << "Draw" << endl;

    return 0;
}