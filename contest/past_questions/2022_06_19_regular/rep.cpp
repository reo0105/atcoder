#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> dist1(105), dist2(105);

    cin >> n;
    for (int i = 3; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        int d;
        cin >> d;
        if (d == -1) return 0;
        dist1.at(i) = d;
    }

    for (int i = 3; i <= n; i++) {
        cout << "? " << 2 << " " << i << endl;
        int d;
        cin >> d;
        if (d == -1) return 0;
        dist2.at(i) = d;
    }

    set<int> mini;
    int ans = 1<<29;

    for (int i = 3; i <= n; i++) {
        if (dist1.at(i) + dist2.at(i)  < ans) {
            ans = dist1.at(i) + dist2.at(i);
            mini.clear();
            mini.insert(i);
        } else if (dist1.at(i) + dist2.at(i) == ans) {
            mini.insert(i);
        }
    }

    return 0;
}