#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int>tup;

int main()
{
    int n, m;
    vector<tup> tmp(400005); //choco(200005), box(200005);

    cin >> n >> m;

    for (int i = 0; i < n; i++) { cin >> get<0>(tmp.at(i)); }
    for (int i = 0; i < n; i++) { cin >> get<1>(tmp.at(i)); get<2>(tmp.at(i)) = 0;}
    for (int i = n; i < n+m; i++) { cin >> get<0>(tmp.at(i)); }
    for (int i = n; i < n+m; i++) { cin >> get<1>(tmp.at(i)); get<2>(tmp.at(i)) = 1;}
    sort(tmp.rbegin(), tmp.rend());

    multiset<int> ms;
    int ok = 1;

    for (int i = 0; i < n+m; i++) {
        tup x = tmp.at(i);
        int ver = get<0>(x), hor = get<1>(x), flag = get<2>(x);

        if (flag == 0) {
            auto mini = ms.lower_bound(hor);
            if (mini == ms.end()) {
                ok = 0;
            } else {
                ms.erase(mini);
            }
        } else {
            ms.insert(hor);
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl; 

    return 0;
}