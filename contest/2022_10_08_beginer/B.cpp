#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, x;
    vector<vector<int>> data(105);
    vector<vector<bool>> check(105, vector<bool>(105, false));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> k;
        data.at(i).push_back(k);
        for (int j = 0; j < k; j++) {
            cin >> x;
            data.at(i).push_back(x);
        }
    }

    for (int i = 0; i < m; i++) {
        k = data.at(i).at(0);
        for (int j = 1; j <= k; j++) {
            for (int l = j+1; l <= k; l++) {
                //if (data.at(i).at(j) == data.at(i).at(l)) {
                    check.at(data.at(i).at(j)).at(data.at(i).at(l)) = true;
                    check.at(data.at(i).at(l)).at(data.at(i).at(j)) = true;
                //}
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!check.at(i).at(j)) {
                cout << "No" << endl;
                goto end;
            }
        }
    }

    cout << "Yes" << endl;

end:
    return 0;
}