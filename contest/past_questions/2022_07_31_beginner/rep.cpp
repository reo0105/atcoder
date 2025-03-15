#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a(500005);

    cin >> n;
    ll same = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
        if (a.at(i) == i) same++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int num = a.at(i);
        if (i != num && i == a.at(num)) cnt++;
    }

    // cout << cnt << " " << same << endl;

    cout << cnt / 2 + same * (same - 1) / 2 << endl;

    return 0;
}