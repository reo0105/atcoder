#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++) {
        double dist = 0;
        int ans = 0;
        int xi = x[i];
        int yi = y[i];
        for (int j = 0; j < n; j++) {
            int xj = x[j];
            int yj = y[j];
            double nd = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
            if (dist < nd) {
                dist = nd;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}