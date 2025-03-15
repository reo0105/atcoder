#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;
    cin >> n;
    vector<int> a(100005);

    for (int i = 0; i < n; i++) cin >> a.at(i);

    int q;
    cin >> q;
    vector<int> l(1000005), r(1000005);
    for (int i = 0; i < q; i++) cin >> l.at(i) >> r.at(i);

    int d = max(1, n/(int)sqrt(q));

    vector<int> qis(1000005);
    for (int i = 0; i <= q; i++) qis.at(i) = i;
    sort(qis.begin(), qis.end(), [&](int i, int j) {
        int di = r.at(i)/d, dj = r.at(j)/d;
        if (di != dj) return di < dj;
        return l.at(i) < l.at(j);
    });

    vector<int> ans(1000005);
    int nl = 0, nr = 0;
    int now = 0;
    for (int qi : qis) {
        while (nl < l.at(qi)) nl++;
        while (nl > l.at(qi)) nl--;
        while (nr < l.at(qi)) nr++;
        while (nr > l.at(qi)) nr--;
        ans.at(qi) = now;
    }
    
}