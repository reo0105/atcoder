#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(1005), b(1005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) cin >> b.at(i);

    int ans0 = 0, ans1 = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == b.at(i)) ans0++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (a.at(i) == b.at(j)) ans1++;
        }
    }

    cout << ans0 << endl;
    cout << ans1 << endl;
    return 0;
}