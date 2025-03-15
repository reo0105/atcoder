#include <bits/stdc++.h>
using namespace std;

int main() {
    // int a, b, c, d, e, f;
    vector<int> coin(6);
    // cin >> a >> b >> c >> d >> e >> f;
    for (int i = 0; i < 6; i++) cin >> coin[i];

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> val = {1, 5, 10, 50, 100, 500};

    int ok = 1;
    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        
        for (int j = 5; j >= 0; j--) {
            int val_j = val[j];
            if (xi >= val_j) {
                int pi = xi / val_j;
                if (pi <= coin[j]) {
                    coin[j] -= pi;
                    xi -= val_j * pi;
                } else {
                    xi -= val_j * coin[j];
                    coin[j] = 0;
                }
            }
        }

        if (xi != 0) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}