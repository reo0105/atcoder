#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, a, cnt = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a % 2 == 1) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}