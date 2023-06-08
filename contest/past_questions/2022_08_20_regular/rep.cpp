#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.rbegin(), a.rend());

    vector<int> b;

    for (int i = 2; i >= 0; i--) b.push_back(a.at(i));
    b.push_back(0);

    ll ans = 0;
    do {
        ll t = 0;
        ll ten = 1;
        for (int i = 0 ; i < 3; i++) {
            t *= ten;
            ten = 1;
            t += b.at(i);
            while(b.at(i+1) / ten) {
                ten *= 10;
            }
        }
        ans = max(ans, t);
    } while(next_permutation(b.begin(), b.end()));

    cout << ans << endl;

    return 0;
}