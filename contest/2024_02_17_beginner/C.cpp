#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int ans = 0;

    for (int i = 1; i < h-1; i++) {
        for (int j = 1; j < w-1; j++) {
            int ni = i;
            int nj = j;
            if (s[ni][nj] == '#') continue;

            for (int k = 0; k < n; k++) {
                if (t[k] == 'L') {
                    nj--;
                } else if (t[k] == 'U') {
                    ni--;
                } else if (t[k] == 'R') {
                    nj++;
                } else {
                    ni++;
                }

                if (s[ni][nj] == '#') break;
                if (k == n-1) ans++;
            }
        }
    }    

    cout << ans << endl;

    return 0;
}