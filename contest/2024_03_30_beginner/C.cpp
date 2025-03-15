#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int ab = a+b;

    for (int i = 0; i < n; i++) {
        d[i] %= ab;
    }

    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) d.push_back(d[i]+ab);

    for (int i = 0; i < 2*n-1; i++) {
        if (d[i+1]-d[i] > b) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}