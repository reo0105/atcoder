#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    vector<int> now(n);
    fenwick_tree<int> tree(m);

    ll ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        tree.add(a[i], 1);
        now[i] = tree.sum(0, a[i]);
        ans += now[i];
    }

    cout << ans << endl;
    vector<pair<int, int>> diff(n);
    vector<int> same(n);
    vector<vector<int>> num(m+1);
    for (int i = 0; i < n; i++)
    {
        same[i] = (int)num[a[i]].size();
        num[a[i]].push_back(i);
    }


    for (int i = 0; i < n; i++)
    {
        diff[i].first = m - a[i];
        diff[i].second = i;
    }

    sort(diff.begin(), diff.end());
    int idx = 0;
    // for (int i = 0; i < n; i++) cout << now[i] << " ";
    // cout << endl;
    for (int i = 1; i < m; i++)
    {

        while (idx < n && diff[idx].first == i)
        {
            ans -= now[diff[idx].second];
            ans += diff[idx].second;
            ans -= same[diff[idx].second];
            // if (i == 3)
            // {
            //     cout << "debug " <<  now[diff[idx].second] << endl;
            //     cout << diff[idx].second <<  " "  << same[diff[idx].second] << endl;
            // }
            
            idx++;


        }
        cout << ans << endl;
    }

    return 0;
}