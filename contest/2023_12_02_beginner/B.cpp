#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, m, l;
    cin >> n >> s >> m >> l;

    int ans = 1e9;

    for (int si = 0; si <= 100 / 6 + 1; si++) {
        for (int mi = 0; mi <= 100 / 8 + 1; mi++) {
            for (int li = 0; li <= 100 / 12 + 1; li++) {
                int sum = si * 6 + mi * 8 + li * 12;
                if (sum < n) continue;
                ans = min(ans, s * si + m * mi + l * li);
            }
        }
    }

    cout << ans << endl;

    return 0;
}