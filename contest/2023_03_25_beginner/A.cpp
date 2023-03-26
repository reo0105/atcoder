#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    set<string> s;

    s.insert("and");
    s.insert("not");
    s.insert("that");
    s.insert("the");
    s.insert("you");

    cin >> n;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        if (s.count(w)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}