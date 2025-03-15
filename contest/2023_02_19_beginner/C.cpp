#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    set<int> s;
    int ans;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int i;
    for (i = 0; i < k; i++) {
        if (!s.count(i)) { ans  = i; break; } 
    }
    if (i == k) ans = k;
    cout << ans << endl;

    return 0;
}