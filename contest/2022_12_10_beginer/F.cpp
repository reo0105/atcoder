#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &a, int k)
{
    vector<int> l, r;

    if (k == -1) return 0;

    for (int x : a) {
        if (x>>k & 1) l.push_back(x);
        else r.push_back(x);
    }

    if ((int)r.size() == 0) return f(l, k-1);
    if ((int)l.size() == 0) return f(r, k-1);

    return min(f(r, k-1), f(l, k-1)) + (1<<k);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    cout << f(a, 30) << endl;

    return 0;
}
