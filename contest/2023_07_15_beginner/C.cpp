#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> st;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string rev(s.rbegin(), s.rend());
        int sz = (int)s.size();

        if (s > rev) {
            st.insert(rev);
        } else {
            st.insert(s);
        }
    }

    cout << st.size() << endl;

    return 0;
}