#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, g, m;

    cin >> k >> g >> m;

    int x = 0, y = 0;

    for (int i = 0; i < k; i++) {
        if (x == g) {
            x = 0;
        } else if (y == 0) {
            y = m;
        } else {
            int add = g - x;
            int sub = y;

            if (add > sub) {
                x += y;
                y = 0;
            } else {
                x = g;
                y -= add;
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}