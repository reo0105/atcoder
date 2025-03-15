#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;

    multiset<ll> ms;

    for (int i = 0; i < q; i++){
        int a, j;
        cin >> a;
        if (a == 1) {
            ll x;
            cin >> x;
            ms.insert(x); 
        } else if (a == 2) {
            ll x, k;
            cin >> x >> k;
            // auto itr = upper_bound(ms.begin(), ms.end(), x);
            auto itr = ms.upper_bound(x);
            for (j = 0; j < k; j++) {
                if (itr == ms.begin()) break;
                itr--;
            }

            if (j == k) cout << *itr << endl;
            else cout << -1 << endl;
        } else {
            ll x, k;
            cin >> x >> k;
            // auto itr = lower_bound(ms.begin(), ms.end(), x);
            auto itr = ms.lower_bound(x);
            for (j = 1; j < k; j++) {
                if (itr == ms.end()) break;
                itr++;
            }

            if (j == k && itr != ms.end()) cout << *itr << endl;
            else cout << -1 << endl;
        }
    }
    
    return 0;
}