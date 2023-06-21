#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1) {
        int n;
        int cnt = 0;
        vector<set<int>> a(1005);

        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            int c1, c2;
            cin >> c1 >> c2;
            if (c1 != c2) {
                a.at(i).insert(c1);
                a.at(i).insert(c2);
            } else cnt++;
        }

        int ans = 0;
        int dec = 0, inc = 1;
        while (cnt != n) {
            while (a.at(dec).empty()) { 
                dec++;
                if (dec == n) dec = 0;
            }

            inc = (dec+1) % n;
            while (a.at(inc).empty()) { 
                inc++;
                if (inc == n) inc = 0;
            }

            ans++;
            int mini = *begin(a.at(dec));
            // cout << mini << " " << dec << " " << inc << endl;
            a.at(dec).erase(mini);
            if (a.at(dec).empty()) cnt++;
            
            if (a.at(inc).count(mini)) {
                a.at(inc).erase(mini);
                if (a.at(inc).empty()) cnt++;
            } else a.at(inc).insert(mini);

            dec = (dec + 1) % n;
            inc = (inc + 1) % n;
        }

        cout << ans << endl;

    }

    return 0;
}