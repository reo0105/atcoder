#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    int q;

    cin >> n >> s >> q;
    set<int> change;
    int flag = -1;

    for (int i = 0; i < q; i++) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        if (t == 1) {
            x--;
            s[x] = c;
            change.insert(x);
        } else if (t == 2) {
            change.clear();
            flag = 2;
        } else {
            change.clear();
            flag = 3;
        }
    }

    for (int i = 0; i < n; i++) {
        if (change.count(i)) continue;
        if (flag == 2 && 'A' <= s[i] && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        } else if (flag == 3 && 'a' <= s[i] && s[i] <= 'z') {
            s[i] += 'A' - 'a';
        }
    }

    cout << s << endl;

}