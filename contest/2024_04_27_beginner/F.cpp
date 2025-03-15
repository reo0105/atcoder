#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;

template<typename T=int>
struct CC {
    bool initialized;
    vector<T> xs;
    CC(): initialized(false) {}

    void add(T x) {
        xs.push_back(x);
    }

    void init() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        initialized = true;
    }

    int operator()(T x) {
        if (!initialized) init();
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
    }

    T operator[](int i) const { 
        if (!initialized) init();
        return xs[i]; 
    }

    int size() {
        if (!initialized) init();
        return (int) xs.size();
    }

};

int main() {
    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<int> pack_a(n);
    set<int> st;
    for (auto [ai, id] : a) {
        st.insert(ai);
        pack_a[id] = (int)st.size();
    }

    // CC<int> cc;
    // for (int i = 0; i < n; i++) cc.add(a[i]);

    fenwick_tree<int> tcnt(n+3);
    fenwick_tree<ll> tsum(n+3);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ai = pack_a[i];
        ans += (ll)a[i].first * tcnt.sum(0, ai);
        ans -= tsum.sum(0, ai);
        tcnt.add(ai, 1);
        tsum.add(ai, a[i].first);
    }

    cout << ans << endl;

    return 0;
}