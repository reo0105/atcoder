#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    string s;
    vector<vector<int>> cnt(26);

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        cnt.at(s.at(i)-'a').push_back(i);
    }

    // for (int i = 0; i < (int)cnt.at(0).size(); i++) {
    //     cout << cnt.at(0).at(i) << endl;
    // }

    int r = n-1;
    
    for (int l = 0; l < r; l++) {
        int c = s.at(l) - 'a';
        for (int i = 0; i < c; i++) {
            if ((int)cnt.at(i).size() == 0) continue;
            int index = upper_bound(cnt.at(i).begin(), cnt.at(i).end(), r) - cnt.at(i).begin() -1;
            // cout << l << " " << i << " " << cnt.at(i).at(index) << endl;
            if (index >= 0 && l < cnt.at(i).at(index)) {
                // cout << l << " " << i << " " << cnt.at(i).at(index) << endl;
                swap(s.at(l), s.at(cnt.at(i).at(index)));
                r = cnt.at(i).at(index) - 1;
                break;
            }
        }
    }

    cout << s << endl;

    return 0;
}