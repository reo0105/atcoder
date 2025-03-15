#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    set<char> st;

    cin >> s;

    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');

    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (st.count(s[i])) continue;
        cout << s[i];
    }
    cout << endl;

    return 0;
}