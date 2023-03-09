#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> p;

int main()
{
    string s, t;
    cin >> s >> t;
    vector<p> cnt0, cnt1;

    char pre = s.at(0);
    int cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (pre != s.at(i)) {
            cnt0.push_back(make_pair(pre, cnt));
            cnt = 1;
            pre = s.at(i);
        } else {
            cnt++;
        }
    }
    cnt0.push_back(make_pair(s.at((int)s.size()-1), cnt));

    pre = t.at(0);
    cnt = 1;
    for (int i = 1; i < (int)t.size(); i++) {
        if (pre != t.at(i)) {
            cnt1.push_back(make_pair(pre, cnt));
            cnt = 1;
            pre = t.at(i);
        } else {
            cnt++;
        }
    }
    cnt1.push_back(make_pair(t.at((int)t.size()-1), cnt));

    // for (auto p : cnt0) {
    //     cout << p.first << " " << p.second << endl;
    // }

    int flag = 1;
    if (cnt0.size() != cnt1.size()) flag = 0;
    else {
        for (int i = 0; i < (int)cnt0.size(); i++) {
            if (cnt0.at(i).first != cnt1.at(i).first) {
                flag = 0;
                continue;
            }

            if (cnt0.at(i).second == 1 && cnt1.at(i).second != 1) {
                flag = 0;
                continue;
            }

            if (cnt0.at(i).second > cnt1.at(i).second) {
                flag = 0;
                continue;
            }
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}