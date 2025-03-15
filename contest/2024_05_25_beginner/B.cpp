#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a, ab;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        ab.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ab.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(ab.begin(), ab.end());

    set<int> st;
    for (int x : a) st.insert(x);

    for (int i = 0; i < n+m-1; i++) {
        if (st.count(ab[i]) && st.count(ab[i+1])) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}