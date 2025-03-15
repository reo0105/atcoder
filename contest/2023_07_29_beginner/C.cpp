#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int l = 0, r = 1e9+1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int num_a = upper_bound(a.begin(), a.end(), mid) - a.begin();
        int num_b = b.end() - lower_bound(b.begin(), b.end(), mid);

        if (num_a >= num_b) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}