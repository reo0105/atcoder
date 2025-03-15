#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    set<string> st;

    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string tmp;
            for (int k = i; k <= j; k++) {
                tmp.push_back(s[k]);
            }
            st.insert(tmp);
        }
    }

    cout << st.size() << endl;

    return 0;
}