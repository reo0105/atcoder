#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n, k;
        string s;
        cin >> n >> k;
        cin >> s;

        k -= n; 
        k /= 2;
        if (k < 2*n) {
            string tmp(s);
            string tmp_inv = "";
            for (int i = 0; i < k; i++) {
                s += tmp.at(n-1-i);
                tmp_inv += tmp.at(n-1-i);
            }
            
            int flag = 1;
            for (int i = 0; i < (n+k)/2; i++) {
                if (s.at(i) != s.at(n+k-1-i)) {
                    flag = 0;
                    break;
                }
            }
            
            tmp_inv += s;
            for (int i = 0; i < (n+k)/2; i++) {
                if (s.at(i) != s.at(n+k-1-i)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            ll res = k % n;
            ll dir = k / n;

            int flag = 1;

            // cout << res << endl;
            
            if (dir%2 == 0) {
                for (int i = 0; i < res/2; i++) {
                    if (s.at(i) != s.at(res-1-i)) {
                        flag = 0;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < res/2; i++) {
                    if (s.at(n- res+i) != s.at(n-1-i)) {
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        
    }


    return 0;
}