#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a;
    cin >> a;
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        int b;
        cin >> b;
        ans = max(ans, b-a+1);
    }

    cout << ans << endl;

    return 0;
}