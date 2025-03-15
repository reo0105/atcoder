#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    vector<int> a(105, 0);

    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) a.at(x) += 1;
        else if (t == 2) a.at(x) = 2;
        else {
            if (a.at(x) == 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}