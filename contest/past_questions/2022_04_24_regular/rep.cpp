#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> t(100005);

    for (int i = 0; i < n; i++) cin >> t.at(i);

    ll now = 0;
    for (int i = 0; i < n; i++) {
        ll k = 1L<<t.at(i);
        now = (now / k + 1) * k;
        // cout << now << " ";
        if (((now>>t.at(i))&1)==0) now = (now / k + 1) * k;
        // cout << now << endl;
    }

    cout << now << endl;

    return 0;
}