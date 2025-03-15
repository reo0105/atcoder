#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> d(m);

    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        sum += d[i];
    }

    // if (m == 1 && d[0] == 1) {
        // cout << 1 << " " << 1 << endl;
        // return 0;
    // }

    sum /= 2;
    sum++;
    for (int i = 0; i < m; i++) {
        if (sum <= d[i]) {
            cout << i+1 << " " << sum << endl;
            break;
        } else {
            sum -= d[i];
        }
    }

    return 0;
}