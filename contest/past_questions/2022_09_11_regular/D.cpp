#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    set<int> s;
    for (int i = 0; i < n*2; i++) {
        int a;
        cin >> a;
        int t = a;// % m;
        if (s.count(t)) s.erase(t);
        else s.insert(t);
    }

    if ((int)s.size() == 0) {
        cout << "Bob" << endl;
        return 0;
    }

    if (m % 2) {
        cout << "Alice" << endl;
        return 0;
    }

    map<int, int> half;
    for (int p : s) {
        half[p % (m/2)]++;
    }

    int cnt = 0;
    int bob = 1;
    n = (int)s.size();
    for (auto p : half) {
        if (p.second % 2) bob = 0;
        cnt += p.second / 2;
    }

    if (cnt % 2) bob = 0;

    if (!bob) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}