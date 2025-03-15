#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;

    vector<vector<int>> a(200005);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            a.at(i).push_back(x);
        }
    }

    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << a.at(s).at(t) << endl;
    }

    return 0;
}