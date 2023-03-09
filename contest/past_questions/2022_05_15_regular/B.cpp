#include <bits/stdc++.h>
using namespace std;

/*
    偶数回目の操作で新しく操作が行えることはない
    奇数回目ならありえる
*/

int main()
{
    int n;
    string s;
    multiset<int> ms;

    cin >> n >> s;

    int ans = 0;
    int num = 0, flag = 0;
    for (int i = 0; i < n-2; i++) {
        int l = 1, r = 1;
        if (s.at(i) == 'A' && s.at(i+1) == 'R' && s.at(i+2) == 'C') {
            int cnt = 1;
            while (i-cnt >= 0 && s.at(i-cnt) == 'A') { l++; cnt++; }
            cnt = 3;
            while (i+cnt < n  && s.at(i+cnt) == 'C') { r++; cnt++; }
            // cout << l << " " << r << endl;
            ms.insert(min(l, r));
        }
    } 

    int si = (int)ms.size();

    // cout << si << endl;
    // for (int i = 0; i < si; i++) cout << blk.at(i) << endl;

    if (si != 0) {
        while (1) {
            if (ans % 2 == 1) {
                auto mini = *begin(ms);
                ms.erase(ms.find(mini));
                ans++;
            } else {
                auto maxi = *rbegin(ms);
                ms.erase(ms.find(maxi));
                if (maxi - 1 != 0) ms.insert(maxi-1);
                ans++;
            }
            if ((int)ms.size() == 0) break;
        }
    }

    cout << ans << endl;

    return 0;
}