#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    set<string> st;
    st.insert("ACE");
    st.insert("BDF");
    st.insert("CEG");
    st.insert("DFA");
    st.insert("EGB");
    st.insert("FAC");
    st.insert("GBD");

    if (st.count(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}