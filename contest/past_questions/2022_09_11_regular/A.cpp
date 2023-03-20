#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int g = 0;
    for (int i = 0; i < n-1; i++) {
        g = gcd(g, abs(a.at(i)-a.at(i+1)));
    }

    if (g == 1) cout << 2 << endl;
    else cout << 1 << endl;

    return 0;
}