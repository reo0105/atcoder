#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> a(7005), id(7005);
    set<int> done;
    
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        id.at(a.at(i)) = i;
    }

    int cnt;
    if (k < a.at(0)) {
        int r = id.at(k);
        for (int i = r; i >= 0; i--) cout << a.at(i) << " ";
        for (int i = r+1; i < n; i++) cout << a.at(i) << " ";
        return 0;
    } else {
        cnt = a.at(0) - 1;

        for (int i = 1; i < n; i++) {
            int num = a.at(i);
            for (int j = 1; j < num; j++) {
                if (i < id.at(j)) cnt++;
                if (cnt == k) {
                    for (int l = 0; l < i; l++) cout << a.at(l) << " ";
                    for (int l = id.at(j); l >= i; l--) cout << a.at(l) << " ";
                    for (int l = id.at(j)+1; l < n; l++) cout << a.at(l) << " ";
                    return 0;
                }
            }
        }

        // cout << cnt << endl;
        
        cnt += n;
        if (cnt >= k) {
            for (int i = 0; i < n; i++) cout << a.at(i) << " ";
            return 0; 
        }

        // cout << cnt << endl;

        for (int i = n-2; i >= 0; i--) {
            int num = a.at(i);
            for (int j = num+1; j <= n; j++) {
                if (i < id.at(j)) cnt++;
                if (cnt == k) {
                    for (int l = 0; l < i; l++) cout << a.at(l) << " ";
                    for (int l = id.at(j); l >= i; l--) cout << a.at(l) << " ";
                    for (int l = id.at(j)+1; l < n; l++) cout << a.at(l) << " ";
                    return 0;
                }
            }
        }

        // cout << cnt << endl;

        for (int i = 0; i < n; i++) {
            int num = a.at(0);
            for (int j = num+1; j <= n; j++) {
                cnt++;
                if (cnt == k) {
                    for (int l = 0; l < i; l++) cout << a.at(l) << " ";
                    for (int l = id.at(j); l >= i; l--) cout << a.at(l) << " ";
                    for (int l = id.at(j)+1; l < n; l++) cout << a.at(l) << " ";
                    return 0;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}