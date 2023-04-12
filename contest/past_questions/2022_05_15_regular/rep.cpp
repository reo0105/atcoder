#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    string s;

    cin >> n >> k >> s;


    for (int i = 1; i <= n; i++) { //答えをiにできるか
        if (n % i != 0) continue;

        vector<vector<int>> cnt(2005, vector<int>(26, 0));
        for (int j = 0; j < n; j++) {
            cnt.at(j % i).at(s.at(j) - 'a')++;
        }

        int mini = 0;
        for (int j = 0; j < i; j++) {
            int maxi = -1;
            for (int k = 0; k < 26; k++) {
                maxi = max(maxi, cnt.at(j).at(k));
            }
            mini += n/i - maxi;
        }

        if (mini <= k) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     string s;

//     cin >> n >> s;

//     multiset<int> ms;

//     int cnt;
//     for (int i = 0; i < n; i++) {
//         if (s.at(i) == 'R') {
//             cnt = 0;
//             for (int j = 1; j <= n; j++) {
//                 if (i-j >= 0 && i+j < n && s.at(i-j) == 'A' && s.at(i+j) == 'C') cnt++;
//                 else break;
//             }
//             if (cnt != 0) ms.insert(cnt);
//         }
//     }

//     int ans = 0;
//     while (ms.size()) {
//         ans++;
//         if (ans % 2 == 1) {
//             int maxi = *rbegin(ms);
//             ms.erase(ms.find(maxi));
//             maxi--;
//             if (maxi != 0) ms.insert(maxi);
//         } else {
//             int mini = *begin(ms);
//             ms.erase(ms.find(mini));
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }