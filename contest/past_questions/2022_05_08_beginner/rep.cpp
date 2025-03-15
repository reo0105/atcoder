#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, cnt = 1;
    vector<int> a(200005, -1), b(200005, -1);
    vector<int> cntb(200005, 0);
    set<int> sb;
    map<int, int> ma;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
        if (ma[a.at(i)] != 0) {
            a.at(i) = ma[a.at(i)];
            continue;
        }
        ma[a.at(i)] = cnt;
        a.at(i) = cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b.at(i);
        if (!sb.count(b.at(i))) {
            sb.insert(b.at(i));
            cntb.at(i) = cntb.at(i-1) + 1;
        } else {
            cntb.at(i) = cntb.at(i-1);
        }
        if (ma[b.at(i)] != 0) {
            b.at(i) = ma[b.at(i)];
            continue;
        }
        ma[b.at(i)] = cnt;
        b.at(i) = cnt;
        cnt++;
    }

    for (int i = 1; i <= n; i++) a.at(i) = max(a.at(i), a.at(i-1));
    for (int i = 1; i <= n; i++) b.at(i) = max(b.at(i), b.at(i-1));


    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (a.at(x) == cntb.at(y) && a.at(x) == b.at(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}