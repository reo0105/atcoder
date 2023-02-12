#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<int, int> a, b;
    vector<long long> dp(100005, -100000000);

    cin >> n;

    for (int i = 1; i <= n-1; i++) {
        int to;
        cin >> to;
        a[i] = to;
    }

    for (int i = 1; i <= n-1; i++) {
        int to;
        cin >> to;
        b[i] = to;
    }

    dp.at(1) = 0;

    for (int i = 1; i <= n-1; i++) {
        dp.at(a.at(i)) = max(dp.at(a.at(i)), dp.at(i)+100);
        dp.at(b.at(i)) = max(dp.at(b.at(i)), dp.at(i)+150); 
    }

    cout << dp.at(n) << endl;
}