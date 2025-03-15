#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, ans = 0;
    string s;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s.at(j) == '#') {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}