#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    vector<vector<p>> a(200005);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int p, e;
            cin >> p >> e;
            a.at(i).push_back(make_pair(p, e));
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto [p, e] : a.at(i)) {
            if ((int)mp[p].size() < 2) {
                mp[p].push_back(e);
                mp[p].push_back(0);
                sort(mp[p].rbegin(), mp[p].rend());
            }
            else {
                mp[p].push_back(e);
                sort(mp[p].rbegin(), mp[p].rend());
                mp[p].resize(2);
            }
        }
    }


    set<vector<p>> done; 
    for (int i = 0; i < n; i++) {
        vector<p> t;
        int j = 0;

        for (auto [p, e] : a.at(i)) {
            if (mp[p].at(0) == e && mp[p].at(0) != mp[p].at(1)) t.push_back(make_pair(p, mp[p].at(1)));
        }        

        done.insert(t);
    }

    cout << done.size() << endl;

    return 0;
}