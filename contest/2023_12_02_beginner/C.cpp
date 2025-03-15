#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> cnt(1000005, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]] += a[i];
    }

    for (int i = 1; i < 1000005; i++) cnt[i] += cnt[i-1];

    for (int i = 0; i < n; i++) {
        cout << cnt[1000004] - cnt[a[i]] << " ";
    }

    cout << endl;

    return 0;
}