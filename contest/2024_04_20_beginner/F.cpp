#include <bits/stdc++.h>
using namespace std;

char flp(char c) {
    if ('A' <= c && c <= 'Z') return (c-'A'+'a');
    else return (c-'a'+'A');
}

void f(int l, int r, int d, string &s, vector<int> &mch) {
    if (d == 0) {
        while (l <= r) {
            if (s[l] == '(') {
                f(l+1, mch[l]-1, 1, s, mch);
                l = mch[l];
            } else {
                cout << s[l];
            }
            l++;
        }
    } else {
        while (l <= r) {
            if (s[r] == ')') {
                f(mch[r]+1, r-1, 0, s, mch);
                r = mch[r];
            } else {
                cout << s[r];
            }
            r--;
        }
    }
}

int main() {
    string s;
    cin >> s;

    int sz = (int)s.size();
    vector<int> mch(sz);

    for (auto &nx : mch) {
        nx = -1;
    }

    int h = 0;
    vector<int> stk;
    for (int i = 0; i < sz; i++) {
        if (s[i] == '(') {
            stk.push_back(i);
            h++;
        } else if (s[i] == ')') {
            mch[i] = stk.back();
            mch[stk.back()] = i;
            stk.pop_back();
            h--;
        } else if (h%2) {
            s[i] = flp(s[i]);
        }
    }

    f(0, sz-1, 0, s, mch);
    cout << endl;
    return 0;
}