#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(100005), b(100005);
    vector<int> dp(100005, -1);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> a.at(i);
    }

    for (int i = 3; i <= n; i++) {
        cin >> b.at(i);
    }

    dp.at(1) = 0;
    dp.at(2) = a.at(2);

    for (int i = 3; i <= n; i++) {
        dp.at(i) = min(dp.at(i-1)+a.at(i), dp.at(i-2)+b.at(i));
    }

    cout << dp.at(n) << endl;

    
    return 0;
}