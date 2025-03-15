#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int maxi = a.back();

    for (int i = n-1; i >= 0; i--) {
        if (a[i] != maxi) {
            cout << a[i] << endl;
            break;
        }
    }

    return 0;
}