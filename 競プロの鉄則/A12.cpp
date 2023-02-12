#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    vector<int> a(100002);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a.at(i);

    int left = -1, right = 1e9+2, mid;
    long long cnt = 0;
    while (right - left > 1) {
        mid = (right + left) / 2;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += mid / a.at(i);
            // if (cnt > k) break;
            // cout << mid << " / " << a.at(i) << endl;
        }
        // cout << cnt <<  " " << k << endl;
        // if (cnt == k) break;
        if (cnt >= k) right = mid;
        else left = mid;
    }

    cout << right << endl;
    
    return 0;
}