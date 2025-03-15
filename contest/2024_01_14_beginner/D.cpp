#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> right(n, 0);
    vector<int> left(n, 0);
    
    left[0] = min(1, a[0]);
    for (int i = 1; i < n; i++) {
        left[i] = min(left[i-1]+1, a[i]);
    }

    right[n-1] = min(1, a[n-1]);
    for (int i = n-2; i >= 0; i--) {
        right[i] = min(right[i+1]+1, a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(left[i], right[i]));
    }

    cout << ans << endl;

    return 0;
}