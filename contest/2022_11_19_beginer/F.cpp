#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> s(20);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    vector<vector<int>> dp(100000, vector<int>(20, -1));

    for (int i = 0; i < n; i++) dp.at(1<<i).at(i) = 1;

    for (int i = 1; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) { //now 
            for (int k = 0; k < n; k++) { //pre
                if (dp.at(i).at(j) != -1)  continue;
                if (j == k) continue;

                int ok = (s.at(k).back() == s.at(j).at(0));
                if (dp.at(i).at(k) != -1 && ok) {
                    ok |= ~dp.at(i).at(k);
                    dp.at(i|())
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp.at((1<<n)-1).at(i)) ans = 1;
    }

    if (ans) cout << "First" << endl;
    else cout << "Second" << endl;
}