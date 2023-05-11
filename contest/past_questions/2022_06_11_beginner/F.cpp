#include <bits/stdc++.h>
using namespace std;

vector<int> pre(200005), in(200005);
vector<int> place(200005);
vector<int> l(200005), r(200005);

int f(int lp, int li, int n)
{
    if (n == 0) return 0;
    int root = pre.at(lp);
    int i = place.at(root);

    if (i < li || i >= li+n) return -1;

    int ls = i-li, rs = n-1-ls;

    l.at(root) = f(lp+1, li, ls);
    r.at(root) = f(lp+1+ls, li+ls+1, rs);
    
    if (l.at(root) == -1 || r.at(root) == -1) return -1;

    return root;
}

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre.at(i);
    for (int i = 0; i < n; i++) cin >> in.at(i);
    for (int i = 0; i < n; i++) place.at(in.at(i)) = i;

    if (f(0, 0, n) != 1) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) cout << l.at(i) << " " << r.at(i) << endl;
    }

    return 0;
}