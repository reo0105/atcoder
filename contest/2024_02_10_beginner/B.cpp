#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;

    cin >> q;
    vector<int> ans;

    for (int i = 0; i < q; i++) {
        int qi, x;
        cin >> qi >> x;
        if (qi == 1) {
            ans.push_back(x);
        } else {
            cout << ans[(int)ans.size()-x] << endl;
        }
    }

    return 0;
}