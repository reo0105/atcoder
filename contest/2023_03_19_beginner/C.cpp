#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> a(100005), b(100005);
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < m; i++) cin >> b.at(i);

    int cnt = 1;
    int ida = 0, idb = 0;
    vector<int> ansa, ansb;

    while (cnt <= n+m) {
        if (ida < n && idb < m && a.at(ida) < b.at(idb)) {
            ansa.push_back(cnt);
            cnt++;
            ida++;
        } else if (ida < n && idb < m && a.at(ida) > b.at(idb)) {
            ansb.push_back(cnt);
            cnt++;
            idb++;
        }

        if (ida == n) {
            ansb.push_back(cnt);
            cnt++;
            idb++;
        } else if (idb == m) {
            ansa.push_back(cnt);
            cnt++;
            ida++;
        }
    }

    for (int i = 0; i < n; i++) cout << ansa.at(i) << " ";
    cout << endl;
    for (int i = 0; i < m; i++) cout << ansb.at(i) << " ";
    cout << endl; 

    return 0;
}