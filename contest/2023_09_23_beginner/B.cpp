#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    vector<int> a;

    cin >> n >> x;
    for (int i = 0; i < n-1; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 1; i < n-2; i++) {
        sum += a[i];
    }
    int rem = x - sum;
    if (rem <= a[0]) {
        cout << 0 << endl;
    } else if (rem <= a[n-2]) {
        cout << rem << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}