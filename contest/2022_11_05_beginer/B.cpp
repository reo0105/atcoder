#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b;
    vector<vector<int>> data(100002);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        data.at(a).push_back(b);
        data.at(b).push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(data.at(i).begin(), data.at(i).end());
    }

    for (int i = 1; i <= n; i++) {
        cout << data.at(i).size();
        for (int j = 0; j < (int)data.at(i).size(); j++) {
            cout << " " << data.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}