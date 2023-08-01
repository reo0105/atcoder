#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    vector<string> s(105);

    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    int ans = 0, now = 0;
    for (int i = 0; i < d; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            if (s.at(j).at(i) == 'o') t++;
        }
        if (t == n) now++;
        else now = 0;
        ans = max(ans, now);
    }

    cout << ans << endl;

    return 0;
}