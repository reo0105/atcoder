#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);

    for (int i = 0; i < m; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int today = i+1;
        int first = *lower_bound(a.begin(), a.end(), today);
        cout << first - today << endl;
    }

    return 0;
}