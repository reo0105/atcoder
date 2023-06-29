#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    multiset<int> calc;
    multiset<int> other;
    vector<int> now(500005, 0);
    
    for (int i = 0; i < k; i++) calc.insert(0);
    for (int i = 0; i < n-k; i++) other.insert(0);

    ll ans = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        calc.insert(y);
        ans += y;
        int mini = *begin(calc);
        calc.erase(calc.find(mini));
        ans -= mini;
        other.insert(mini);

        if (calc.find(now.at(x)) != calc.end()) {
            calc.erase(calc.find(now.at(x)));
            ans -= now.at(x);
            int maxi = *rbegin(other);
            calc.insert(maxi);
            other.erase(other.find(maxi));
            ans += maxi;
        } else {
            other.erase(other.find(now.at(x)));
        }

        now.at(x) = y;

        cout << ans << endl;
    }

    return 0;
}