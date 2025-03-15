#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    vector<int> a(200002);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a.at(i);

    int l = a.at(0);
    w = a.at(n-1) - a.at(0);
    int g = w;
    for (int i = 0; i < n; i++) {
        g = gcd(g, 2*(a.at(i)-l));
    }
    cout << l % g + w << endl;

    return 0;
}