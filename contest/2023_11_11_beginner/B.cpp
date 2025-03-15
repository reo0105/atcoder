#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> d(n+1);
    for(int i = 1; i <= n; i++) cin  >> d[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int ten_i = i / 10;
        int one_i = i % 10;
        if (ten_i != 0 && ten_i != one_i) continue;
        for (int j = 1; j <= d[i]; j++) {
            int ten = j / 10;
            int one = j % 10;
            if (ten == 0 && one_i == one) ans++;
            else if (ten != 0 && one_i == ten && ten == one) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}