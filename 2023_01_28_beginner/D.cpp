#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    string s, t;
    int ns, nt;

    cin >> s >> t;
    ns = (int)s.size();
    nt = (int)t.size();

    // string tmp(s);
    // reverse(tmp.begin(), tmp.end());
    // cout << s << endl;

    // s += tmp;
    // cout << s;

    // int loop = 0;
    // for (int i = 0; i < nt; i++) {
    //     if (t.a)
    // }

    int flag = 1;
    for (int i = 0; i <= nt; i++) {
        int cnt = 0;

        if (flag && i != 0) {
            cnt += i-1;
            for (int j = i-1; j < i; j++) {
                if (s.at(j) == t.at(j) || s.at(j) == '?' || t.at(j) == '?') cnt++;
                else {flag = 0; break;}
            }
        }

        // cout << flag << endl;

        if (flag) {
            for (int j = i; j < nt; j++) {
                if (s.at(ns-nt+j) == t.at(j) || s.at(ns-nt+j) == '?' || t.at(j) == '?') cnt++;
                else break;
            }
        }

        if (cnt == nt) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

