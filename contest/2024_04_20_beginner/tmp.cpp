#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void flip(string &s, int id, int flag) {
    if (flag) {
        if ('A' <= s[id] && s[id] <= 'Z') {
            s[id] = s[id] - 'A' + 'a';
        } else {
            s[id] = s[id] - 'a' + 'A';
        }
    }
}

int main() {
    string s;
    cin >> s;

    int sz = (int)s.size();

    int cnt = 0;
    vector<int> match(sz);
    stack<int> stk;
    
    for (int i = 0; i < sz; i++) {
        if (s[i] == '(') {
            cnt++;
            stk.push(i);
        } else if (s[i] == ')') {
            cnt--;
            int mch = stk.top();
            stk.pop();
            match[mch] = i;
            match[i] = mch; 
        } else flip(s, i, cnt%2);
    }

    auto f = [&](auto f, int l, int r, int d) -> void {
        if (d == 0) {
            while (l <= r) {
                if (s[l] == '(') {
                    f(f, l+1, match[l]-1, 1);
                    l = match[l];
                } else {
                    cout << s[l];
                }
                l++;
            }
        } else {
            while (l <= r) {
                if (s[r] == ')') {
                    f(f, match[r]+1, r-1, 0);
                    r = match[r];
                } else {
                    cout << s[r];
                }
                r--;
            }
        }
    };

    f(f, 0, sz-1, 0);
    cout << endl;

    return 0;
}