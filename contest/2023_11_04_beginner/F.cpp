#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

struct event{
    int l, r, x;
    event(int l = 0, int r = 0, int x = 0): l(l), r(r), x(x) {}
};

int op(int x, int y) { return max(x, y); }
int e() { return 0; }
int mapping(int f, int x) { return x += f; }
int composition(int f, int g) { return f+g; }
int id() { return 0; }

int main()
{
    int n, d, w;
    cin >> n >> d >> w;

    const int MX = 400005;

    vector<vector<event>> events(MX); 
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        events[t].emplace_back(x, x+w, 1);
        events[t+d].emplace_back(x, x+w, -1);
    }

    int ans = -1e9;
    lazy_segtree<int, op, e, int, mapping, composition, id> seg(MX);
    for (int i = 0; i < MX; i++) {
        for (auto event: events[i]) {
            seg.apply(event.l, event.r, event.x);
        }
        ans = max(ans, seg.all_prod());
    }

    cout << ans << endl;

    return 0;
}