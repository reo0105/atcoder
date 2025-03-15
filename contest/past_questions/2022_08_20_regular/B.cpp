#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, k;
    vector<int> a;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int x;   
        cin >> x;
        a.push_back(x);
    }

    // sort(a.begin(), a.end());

    // cout << sumk << endl;

    ll ans = 0, flag = 1;
    int mask = (1<<31) - 1;
    for (int i = 30; i >= 0; i--) {
        for (int j = 0; j < n; j++) a.at(j) &= mask;
        
        if (flag) {
            sort(a.begin(), a.end());
        }

        // for (int i = 0; i < n; i++) cout << a.at(i) << " ";
        // cout << endl; 

        ll t = 0;
        for (int j = n-1; j > n-1-k; j--) {
            if (((a.at(j)>>i) & 1) == 0) {
                t += (1<<i) - a.at(j);
            }
        }

        if (t <= m) { 
            ans += 1<<i;
            m -= t;
            //cout << i << " " << m << " " << t << endl;
            if (t != 0) { //大きい方からk個で確定
                for (int j = n-1; j > n-1-k; j--) {
                    if (((a.at(j)>>i) & 1) == 0) {
                        a.at(j) = (1<<i);
                        // t += (1<<i) - a.at(j);
                    }
                } 
                flag = 0;
            } else { //今見てるビットについて大きい方からk個全部1なのでまたソートが必要。
                for (int j = n-1; j >= 0; j--) {
                    if (((a.at(j)>>i) & 1) == 0) {
                        a.at(j) = 0;
                        // cout << "j " << j << endl;
                        // t += (1<<i) - a.at(j);
                    }
                }
            }
            // flag = 0;
        }
        mask >>= 1;
    }

    cout << ans << endl;

    return 0;
}