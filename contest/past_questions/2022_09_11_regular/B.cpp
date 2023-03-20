#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'p') {
            l = i;
            break;
        }
    }

    int cnt = 0;
    int max = 0;
    string ans(s);
    for (int i = n-1; i >= 0; i--) {
        string t;
        if (cnt != 0 && s.at(i) == 'd') {
            r = i+cnt;
            for (int i = 0; i < l; i++) t.push_back('d');
            for (int i = r; i >= l; i--) {
                if (s.at(i) == 'd') t.push_back('p');
                else t.push_back('d');
            }
            for (int i = r+1; i < n; i++) t.push_back(s.at(i));
            ans = min(ans, t);
            cnt = 0;
            continue;
        } else if (s.at(i) == 'p') {
            cnt++;
        }
    }

    if (cnt != 0) {
        string t;
        r = cnt-1;
        for (int i = 0; i < l; i++) t.push_back('d');
        for (int i = r; i >= l; i--) {
            if (s.at(i) == 'd') t.push_back('p');
            else t.push_back('d');
        }
        for (int i = r+1; i < n; i++) t.push_back(s.at(i));
        ans = min(ans, t);
    }


    cout << ans << endl;

    return 0;
}
