#include <bits/stdc++.h>
using namespace std;

vector<int> dp(10005); //, vector<int>(105, 0));

int main()
{
    int n, k;
    vector<int> a(105);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a.at(i);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= a.at(j)) dp.at(i) = max(dp.at(i), i - dp.at(i-a.at(j)));
        }
    }

    cout << dp.at(n);
}