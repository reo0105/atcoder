#include <bits/stdc++.h>
using namespace std;
#define INF 1<<29

int main()
{
    int n;
    vector<int> p(200005), q(200005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p.at(i);
    for (int i = 0; i < n; i++) cin >> q.at(i);

    vector<int> pos(200005);

    for (int i = 0; i < n; i++) pos.at(q.at(i)) = i;

    vector<pair<int, int>> pa;
    for (int i = 0; i < n; i++) {
        for (int j = p.at(i); j <= n; j += p.at(i)) {
            pa.push_back(make_pair(i, -1 * pos.at(j)));
        }
    }

    sort(pa.begin(), pa.end());
    vector<int> tmp;

    for (auto x : pa) {
        tmp.push_back(-1*x.second);
    }

    vector<int> dp(200005, INF);
    for (int x : tmp) {
        auto itr = lower_bound(dp.begin(), dp.end(), x);

        *itr = x;
    }

    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;
    
    return 0;
}