#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> c(n);
    vector<deque<int>> order(m+1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        order[c[i]].push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        int tail = order[i].back();
        order[i].pop_back();
        order[i].push_front(tail);
    }

    for (int i = 0; i < n; i++) {
        int nc = c[i];
        int ans = order[nc].front();
        order[nc].pop_front();
        cout << s[ans];
    }
    cout << endl;

}