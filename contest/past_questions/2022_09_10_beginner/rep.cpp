#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> s;
set<string> st;
set<int> done;

void dfs(int id, string now, int rem)
{
    // cout << id << " " << "in" << endl;
    if (id != n-1) now += '_';

    // cout << now << endl;
    if (id == n-1 && !st.count(now)) {
        cout << now << endl;
        exit(0);
    } else if (id == n-1) return;

    if (rem != 0) dfs(id, now, rem-1);
    if (id != n-1) dfs(id+1, now+s.at(id+1), rem);
    // cout << id << " " << "out" << endl;
}

int main()
{
    cin >> n >> m;

    int l = 0;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s.push_back(t);
        l += (int)s.at(i).size();
    }
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        st.insert(t);
    }

    if (n == 1) {
        if (st.count(s.at(0))) cout << -1 << endl;
        else if ((int)s.at(0).size() >= 3) cout << s.at(0) << endl;
        else cout << -1 << endl;
        return 0;
    }

    sort(s.begin(), s.end());
    int rem = 16 - l - (n-1);

    do {
        dfs(0, s.at(0), rem);
    } while(next_permutation(s.begin(), s.end()));
    

    cout << -1 << endl;

    return 0;
}