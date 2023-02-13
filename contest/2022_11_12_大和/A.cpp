#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, cnt = 0, ans = 0;
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cnt++;
        if (tmp == k) ans = cnt;
    }

    cout << ans << endl;

    return 0;
}