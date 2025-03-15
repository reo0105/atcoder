#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int h;
    cin >> h;
    vector<int> a(n-1);
    for (int i = 0; i < n-1; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        if (h < a[i]) {
            cout << i+2 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}