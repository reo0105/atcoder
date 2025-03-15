#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> tee(n, 1);
    for (int i = 0 ; i < q; i++) {
        int t;
        cin >> t;
        t--;
        if (tee[t]) { tee[t] = 0; n--; }
        else { tee[t] = 1; n++; }
    }

    cout << n << endl;

    return 0;
}