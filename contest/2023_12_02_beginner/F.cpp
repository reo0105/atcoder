#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
typedef pair<ll, int> pii;

const int p1 = 1000000021;
const int p2 = 1000000033;

struct mints {
    int d1, d2;
    mints(int val=0): d1(val), d2(val) {}
    mints(int d1, int d2): d1(d1), d2(d2) {}
    mints operator+(const mints& a) const {
        return mints((d1+a.d1)%p1, (d2+a.d2)%p2);
    }
    mints operator*(const mints& a) const {
        return mints(((ll)d1*a.d1)%p1, ((ll)d2*a.d2)%p2);
    }
    bool operator==(const mints& a) const {
        return d1 == a.d1 && d2 == a.d2;
    }
};


struct D {
    mints h, c;
    D() {}
    D(mints h, mints c): h(h), c(c) {}
};

D op(D a, D b) {
    return D(a.h+b.h*a.c, a.c*b.c);
}

D e() {return D(0,1); }


int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
   
    int x = rand() % p1;

    segtree<D,op,e> t1(n), t2(n);

    for (int i = 0; i < n; i++) {
        t1.set(i, D(s[i], x));
        t2.set(n-1-i, D(s[i], x));
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int t;
            char c;
            cin >> t >> c;
            t--;
            t1.set(t, D(c, x));
            t2.set(n-1-t, D(c, x));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            mints h1 = t1.prod(l, r).h;
            mints h2 = t2.prod(n-r, n-l).h;
            if (h1 == h2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }


    return 0;
}