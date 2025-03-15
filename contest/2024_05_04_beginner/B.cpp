#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

    set<char> st;
    for (int i = 0; i < (int)s.size(); i++) st.insert(s[i]);

    int cnt = 0;
    for (int i = 0; i < (int)t.size(); i++) {
        if (s[cnt] == t[i]) {
            cout << i+1 << " ";
            cnt++;
        }
    }
    cout << endl;

    return 0;
}