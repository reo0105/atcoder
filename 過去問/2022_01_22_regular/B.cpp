#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> tmp)
{
    vector<int> dp;
    
    for (auto ele : tmp) {
        auto it = lower_bound(dp.begin(), dp.end(), ele);

        if (it == dp.end()) {
            dp.push_back(ele);
        } else {
            *it = ele;
        }
    }

    return (int)dp.size();
}


int main()
{
    int n;
    vector<int> p(200005), q(200005, -1);

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

    for (int i = 0; i < (int)pa.size(); i++) {
        tmp.push_back(pa.at(i).second * -1);
    }

    cout << lis(tmp) << endl;
}