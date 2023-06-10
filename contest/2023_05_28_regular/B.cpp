#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        ll n;
        cin >> n;

        if (n < 7) cout << -1 << endl;
        else {
            vector<int> one;
            ll tmp = n;
            int cnt = 1;

            while (tmp > 0) {
                if (tmp & 1) one.push_back(cnt); 
                tmp >>= 1;
                cnt++;
            }

            ll two = 1;
            int sz = (int)one.size();
            sort(one.rbegin(), one.rend());
            int drop = 0;

            if (sz >= 3) {
                for (int k : one) {
                    if (drop < 3) drop++;
                    else {
                        ll two = 1L<<(k-1);
                        n ^= two;
                    }
                }
                cout << n << endl;
            } else {
                int k = 0;
                ll two = 1;
                int now = sz;
                sort(one.begin(), one.end());

                for (int x : one) {
                    if (x == 1) { n ^= 1; now -= 1; continue;}
                    else if (x == 2) { n ^= 2; now -= 1; continue;}
                    else if (now == 2){
                        n ^= 1L<<(x-1);
                        n |= 1L<<(x-2);
                        n |= 1L<<(x-3);
                    } else {
                        n ^= 1L<<(x-1);
                        n |= 1L<<(x-2);
                        n |= 1L<<(x-3);
                        n |= 1L<<(x-4);
                    }
                    break;
                }

                // while (n / two != 0) {
                //     k++;
                //     two *= 2;
                // }
                // // cout << k << " ";
                // ll ans = 1L<<(k-2) | 1L<<(k-3) | 1L<<(k-4);
                cout << n << endl;
            }
        }
    }

    return 0;
}