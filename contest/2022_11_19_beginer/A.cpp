#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    vector<int> a(202, 0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    for (int i = k; i < k+n; i++) {
        cout << a.at(i) << " ";
        if (i == k+n-1) cout << endl;
    }

    return 0;
}