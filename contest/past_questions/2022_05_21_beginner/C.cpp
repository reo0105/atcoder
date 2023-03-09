#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> s(105);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    vector<vector<int>> cnt(10, vector<int>(10, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cnt.at(s.at(i).at(j) - '0').at(j)++;
        }
    }

    int ans = 1<<29;
    for (int i = 0; i < 10; i++) {
        int maxi = 0;
        for (int j = 0; j < 10; j++) {
            maxi = max(maxi, (cnt.at(i).at(j) - 1)*10+j);
        }
        ans = min(ans, maxi);
    }

    cout << ans << endl;


    return 0;
}