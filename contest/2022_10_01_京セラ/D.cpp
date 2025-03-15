#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    vector<int> a(105), b(105);
    vector<vector<int>> dp(105, vector<int>(10005, 0));

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        cin >> b.at(i);
    }

    dp.at(0).at(0) = 1;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp.at(i).at(j) == 1) {
                if (j+a.at(i) <= s) dp.at(i+1).at(j+a.at(i)) = 1;
                if (j+b.at(i) <= s) dp.at(i+1).at(j+b.at(i)) = 1;
            }
        }
    }

    if (dp.at(n).at(s) == 1) {
        cout << "Yes" << endl;
        string s(n);
        for (int i = n-1; i>=0; i--) {
            if (s >= a.at(i) && dp.at(i).at(s-a.at(i))) {
                s.at(i) = 'H';
                s -= a.at(i);
            } else {
                s.at(i) = 'T';
                s -= b.at(i);
            }
        }
        cout << s << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}