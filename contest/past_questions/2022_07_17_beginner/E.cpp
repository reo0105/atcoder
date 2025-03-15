#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<p> ab(200005);
    vector<vector<int>> is(200005);
    for (int i = 1; i <= n; i++) {
        cin >> ab.at(i).first >> ab.at(i).second;
        is.at(ab.at(i).first).push_back(i);
        is.at(ab.at(i).second).push_back(i);
    }

    int right = 1;
    vector<int> cnt(200005, 0);
    vector<int> ans(200005, 0);
    int out = n;
    for (int left = 1; left <= m; left++) {
        while (right <= m && out != 0) {
            /* 実際に right を 1 進める */
            for (int x : is.at(right)) {
                if (cnt.at(x) == 0) out--;
                cnt.at(x)++;
            }
            right++;
        }

        // cout << left << " " << right << endl;

        if (out != 0) break;

        ans.at(right-left) += 1;
        ans.at(m+1-left+1) -= 1;

        for (int x : is.at(left)) {
            cnt.at(x)--;
            if (cnt.at(x) == 0) out++;
        }
    }

    for (int i = 1; i < m; i++) ans.at(i+1) += ans.at(i);

    for (int i = 1; i <= m; i++) cout << ans.at(i) << " ";
    cout << endl;

    return 0;
}