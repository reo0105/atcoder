#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, a, b;
    vector<int> x(300005);
    
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {  
       cin >> x.at(i);
    }
    
    int l = 1, r = 1e9+5;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        ll cnta = 0;
        ll cntb = 0;
        for (int i = 1; i <= n; i++) {
            int diff = mid - x.at(i);
            if (diff > 0) cnta += (diff - 1) / a + 1;
            else cntb += abs(diff) / b;
        }

        if (cnta > cntb) r = mid;
        else l = mid;
    }

    cout << l << endl;

    return 0;
}