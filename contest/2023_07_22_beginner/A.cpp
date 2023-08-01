#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    set<char> st;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        st.insert(s.at(i));
        if ((int)st.size() == 3){
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}