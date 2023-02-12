#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n, k;
    vector<p> a;

    cin >> n >> k;

    ll s = 0;
    for (int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        p tmp(x, -i);
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());


    int mi = -1e9, ans = 1e9;
    for (int i = 0; i < n; i++) {
        p tmp = a.at(i);
        int j = -tmp.second;
        cout << j << endl;
        if (j < k) mi = max(mi, j);
        else ans = min(ans, j-mi);
    }

    if (ans == 1e9) ans = -1;

    cout << ans << endl;


}