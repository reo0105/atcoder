#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        sum += a;
    }

    cout << -sum << endl;

    return 0;
}