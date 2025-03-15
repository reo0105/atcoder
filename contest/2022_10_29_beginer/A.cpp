#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans;
    int max = -1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
            ans = i+1;
        }
    }

    cout << ans << endl;

    return 0;
}