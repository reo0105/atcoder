#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll k;
    ll num = 0;

    cin >> k;

    for (ll i = 1; i*i <= k; i++) {
        num += (i-1) * (i-1) + 1;

        if (num >= k) {
            num -= (i-1) * (i-1) + 1;
            ll j;
            for (j = 0; j < k-num; j++) {
                num++;
                if (num == k) break;
            }
            
            string ans(i);
            ans.at(0) = '2';
            for (int l = 0; l < i; l++) {
                if ((j >> l) & 1) ans.at(l) = '2';
                else ans.at(l) = '0'; 
            }
        }
    }

    cout << ans << endl;

    return 0;
}

// int main()
// {
//     ll k;
//     cin >> k;
//     string ans;

//     while (k > 0) {
//         if (k % 2 == 1) ans.push_back('2');
//         else ans.push_back('0');
//         k >>= 1;
//     }

//     reverse(ans.begin(), ans.end());

//     cout << ans << endl;
// }