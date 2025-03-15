#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

struct D {
    int mx, l, r;
};
D op(D a, D b)

struct S {
    int w;
    int max0, l0, r0;
    int max1, l1, r1;
};

S op(S a, S b) {
    S c;
    c.w = a.w+b.w;
    {
        c.max0 = max({a.max0, b.max0, a.r0+b.l0});
        if (a.l0 == a.w) c.l0 = b.l0 + a.w;
        else c.l0 = a.l0;
        if (b.r0 == b.w) c.r0 = a.r0 + b.w;
        else c.r0 = b.r0;
    }
    return c;
}

int main()
{
    lazy_segtree<>

    return 0;
}