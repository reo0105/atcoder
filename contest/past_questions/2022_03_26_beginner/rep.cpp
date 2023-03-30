#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<p> ab(n), cd(m); //, c(200005), d(200005);

    for (int i = 0; i < n; i++) cin >> ab.at(i).first;
    for (int i = 0; i < n; i++) cin >> ab.at(i).second;
    for (int i = 0; i < m; i++) cin >> cd.at(i).first;
    for (int i = 0; i < m; i++) cin >> cd.at(i).second;
    
    sort(ab.rbegin(), ab.rend());
    sort(cd.rbegin(), cd.rend());
    multiset<int> ms;
    int id = 0;
    bool ok = true;

    for (p choco : ab) {
        int tate = choco.first;
        int yoko = choco.second;

        while (id < m && cd.at(id).first >= tate) {
            ms.insert(cd.at(id).second);
            id++;
        }

        auto itr = ms.lower_bound(yoko);
        if (itr == ms.end()) ok = false;
        else ms.erase(itr);
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}