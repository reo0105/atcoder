#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m;
    vector<string> s(100005);
    set<string> t;
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.at(i) = tmp;
    }
 
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        t.insert(tmp);
    }
 
    for (int i = 0; i < n; i++) {
        if (t.count(s.at(i))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
 
    return 0;
}