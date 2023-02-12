#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    int size0, size1;
    vector<vector<int>> dp(2002, vector<int>(2002, 0));

    cin >> s >> t;

    size0 = (int)s.size();
    size1 = (int)t.size();

    for (int i = 1; i <= size0; i++) {
        for (int j = 1; j <= size1; j++) {
            if (s.at(i-1) == t.at(j-1)) {
                dp.at(i).at(j) = max(dp.at(i-1).at(j-1) + 1, dp.at(i).at(j));
            } else {
                dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i).at(j-1));
            }
        }
    }

    cout << dp.at(size0).at(size1) << endl;

    vector<int> index;
    int num = dp.at(size0).at(size1);
    // int i = size0;

    // for (int i = size0; i >= 1; i--) {
        for (int j = size1; j >= 1; j--) {
            if (dp.at(size0).at(j) != dp.at(size1).at(j-1)) {
                index.push_back(j-1);
            }
        }
    // }

    for (int i = (int)index.size()-1; i >= 0; i--) {
        cout << t.at(index.at(i));
    }

    cout << endl;

    return 0;
}