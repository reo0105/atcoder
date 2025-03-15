#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    set<int> st;

    st.insert(1);
    st.insert(2);
    st.insert(3);

    st.erase(a);
    st.erase(b);

    if ((int)st.size() == 2) {
        cout << -1 << endl;
    } else {
        cout << *st.begin() << endl;
    }

    return 0;
}