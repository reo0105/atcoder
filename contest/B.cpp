#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main()
{
    int n, k;
    cin >> n >> k;
    // vector<int> a(200005);
    set<multiset<int>> s;
    multiset<int> ms;
    for (int i = 0; i < n ; i++) {
        int a;
        cin >> a;
        ms.insert(a);
    }

    vector<int> dp(200005, 0);
    dp.at(0) = 1;

    for (int i = 1; i <= k; i++) {
        dp.at(i) = dp.at(i-1)
    }

    return 0;
}