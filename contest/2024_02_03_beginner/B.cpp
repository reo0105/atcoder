#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<string> s(h);

    string t(w, '.');

    for (int i = 0; i < h; i++) {
        s[i] = t;
    }

    int i = 0, j = 0;
    int dir = 0;

    for (int li = 0; li < n; li++) {
        if (s[i][j] == '.') {
            s[i][j] = '#';
            dir++;
            if (dir == 4) dir = 0;
        } else {
            s[i][j] = '.';
            dir--;
            if (dir == -1) dir = 3;
        }

        if (dir == 0) i--;
        else if (dir == 1) j++;
        else if (dir == 2) i++;
        else j--;

        if (i == -1) i = h-1;
        else if (i == h) i = 0;
        if (j == -1) j = w-1;
        else if (j == w) j = 0;
    }

    for (int i = 0; i < h; i++) cout << s[i] << endl;

    return 0;
}