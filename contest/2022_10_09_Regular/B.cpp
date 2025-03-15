#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;
    vector<p> x;
    // vector<int> b(300005);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        x.push_back(make_pair(a, 0));
    }

    for (int i = 0 ; i < n; i++) {
        int b;
        cin >> b;
        x.at(i).second = b;
    }

    sort(x.begin(), x.end());


    vector<int> dp(3000005, 1<<29);

    for (int i = 0; i < n; i++) {
        auto itr = lower_bound(dp.begin(), dp.end(), x.at(i).second);

        *itr = x.at(i).second;
    }

    int ans = lower_bound(dp.begin(), dp.end(), 1<<29) - dp.begin();

    ans += n;

    cout << ans << endl;

    return 0;
}