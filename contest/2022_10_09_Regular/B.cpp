#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, befor = 0, cnt = 0, after = 0;
    int left = 0, right = 0;
    bool ans = false;
    vector<int> n(100005), k(100005);
    vector<string> s(100005);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n.at(i) >> k.at(i);
        cin >> s.at(i);
    }

    for (int i = 0; i < t; i++) {
        left = 0; right = 0; cnt = 0;
        for (int j = 0; j < n.at(i); j++) {
            // if (befor == 0 && s.at(j) == '?') {
            //     befor++;
            // } else if (s.at(j) == '1') {
            //     cnt++;
            // } else if (s.at(j) == '?') {
            //     after++;
            // } else if (j == n.at(i) - k.at(i) - 1 || s.at(j) == '0'){
            //     if (cnt < k.at(i) && after + cnt >= k.at(i)) {
            //         ans = true;
            //     }
            //     befor = 0;
            //     after = 0;
            // }
            if (s.at(i).at(j) == '1' || s.at(i).at(j) == '?') right++;
            else {
                left++;
            }

            if (left > right) right = left;

            if (right - left == k.at(i) && ((right < n.at(i) && s.at(i).at(right) != '1') && (left >=1 && s.at(i).at(left-1) != '1'))) {
                cnt++;
                left++;
            }
        }

        if (cnt == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }

    return 0;
}