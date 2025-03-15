#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<vector<int>> ans(505, vector<int>(505, 0));

    cin >> n;
    for (int i = 1; i <= n; i++) ans.at(1).at(i) = i;
    for (int i = 1; i <= n; i++) ans.at(n).at(i) = (n-1)*n+i;

    if (n > 2) {
        int cnt = 1;
        for (int i = n; i >= 1; i-=2) {
            ans.at(2).at(i) = n+cnt;
            cnt++;
        }

        for (int i = n-1; i >= 1; i-=2) {
            ans.at(2).at(i) = n+cnt;
            cnt++;
        }
    }

    if (n > 3) {
        for (int i = 3; i <= n-1; i++) {
            for(int j = 1; j <= n; j++) {
                ans.at(i).at(j) = ans.at(i-1).at(j) + n;
            }
        }
    }


    for (int i = 1; i <= n ;i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}