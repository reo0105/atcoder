#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int cnt = a[0];
    for (int i = 1; i < n; i++) {
        if (cnt+1 != a[i]) {
            cout << cnt+1 << endl;
            break;
        } else {
            cnt = a[i];
        }
    }

    return 0;
}