#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    vector<int> a(105), b(105), c(205);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) cin >> a.at(i);
    for (int i = 0; i <= m+n; i++) cin >> c.at(i);

    for (int i = m; i >= 0; i--) {
        b.at(i) = c.at(i+n) / a.at(n);
        for (int j = 0; j <= n; j++) c.at(i+j) -= b.at(i)*a.at(j);
    }

    for (int i = 0; i <= m; i++) cout << b.at(i) << " ";
    cout << endl; 

    return 0;
}