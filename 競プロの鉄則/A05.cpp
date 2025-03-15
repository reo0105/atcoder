#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, cnt=0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (k-i-j >=1 && k-i-j <= 3000) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}