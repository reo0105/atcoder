#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;

    cin >> n >> x;

    vector<int> a(105), b(105);
    vector<vector<bool>> dp(105, vector<bool>(10005, false));

    for (int i = 1; i <= n; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    dp.at(0).at(0) = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= a.at(i) && dp.at(i-1).at(j-a.at(i))) dp.at(i).at(j) = true;
            if (j >= b.at(i) && dp.at(i-1).at(j-b.at(i))) dp.at(i).at(j) = true;  
        }
    }


    if (dp.at(n).at(x)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}