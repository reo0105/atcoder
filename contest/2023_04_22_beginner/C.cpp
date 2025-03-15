#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;


    cin >> n >> s;

    int ans = -1;
    int cnt = 0;
    int flag = 0;
    int flag1 = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'o') {
            cnt++;
            flag = 1;
        }
        else {
            ans = max(ans, cnt);
            cnt = 0;
            flag1 = 1;
        }
    }

    ans = max(ans, cnt);

    if (!flag || !flag1) ans = -1;

    cout << ans << endl;

    return 0;
}