#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string t;

    cin >> n >> t;

    int x = 0, y = 0, dir = 0;

    for(int i = 0; i < n; i++) {
        if (t.at(i) == 'S') {
            if (dir == 0) x++;
            else if (dir == 1) y--;
            else if (dir == 2) x--;
            else y++;
        } else {
            if (dir == 0) dir++;
            else if (dir == 1) dir++;
            else if (dir == 2) dir++;
            else dir = 0;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
