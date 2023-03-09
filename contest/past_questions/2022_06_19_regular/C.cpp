#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, d;
    cin >> n;

    vector<int> dist1(105);
    vector<int> dist2(105);

    for (int i = 3; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl << flush;
        cin >> d;
        if (d == -1) return 0;
        dist1.at(i) = d;
    }

    for (int i = 3; i <= n; i++) {
        cout << "? " << 2 << " " << i << endl << flush;
        cin >> d;
        if (d == -1) return 0;
        dist2.at(i) = d;
    }

    // int u = abs(dist1.at(3) - dist2.at(3));
    int v = 1<<29;
    set<int> mini;

    for (int i = 3; i <= n; i++) {
        if (v > dist1.at(i) + dist2.at(i)) {
            v = dist1.at(i) + dist2.at(i);
            mini.clear();
            mini.insert(i);
        } else if (v == dist1.at(i) + dist2.at(i)) {
            mini.insert(i);
        }
    }

    if (v == 3 && (int)mini.size() == 2) {
        int x = *begin(mini);
        int y = *rbegin(mini);
        cout << "? " << x << " " << y << endl << flush;
        cin >> d;
        if (d != 1) v = 1; 
    } else if (v == 3) v = 1;

    cout << "! " << v << endl;

    return 0;
}