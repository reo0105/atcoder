#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n+1, -1);
    vector<int> tmp(k+2);

    int total = 0;
    for (int i = 1; i <= k+1; i++) {
        cout << "? ";
        for (int j = 1; j <= k+1; j++) {
            if (i == j) continue;
            cout << j << " ";
        }
        cout << endl;

        int x;
        cin >> x;

        tmp[i] = x;
        total ^= x;
    }

    for (int i = 1; i <= k+1; i++) {
        ans[i] = total ^ tmp[i];
    }

    total = 0;
    for (int i = 1; i < k; i++) {
        total ^= tmp[i];
    } 

    for (int i = k+2; i <= n; i++) {
        cout << "? ";
        for (int j = 1; j < k; j++) {
            cout << j << " ";
        }
        cout << i << endl;

        int x;
        cin >> x;
        ans[i] = total ^ x;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}