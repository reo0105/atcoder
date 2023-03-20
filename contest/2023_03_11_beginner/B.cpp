#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(200005);
    vector<bool> call(200005, false);
    cin >> n;

    int cnt = 0;

    for (int i = 1; i <= n; i++) cin >> a.at(i);

    for (int i = 1; i <= n; i++) {
        if (call.at(i)) continue;

        call.at(a.at(i)) = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!call.at(i)) cnt++;
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (!call.at(i)) cout << i << " ";
    }
    cout << endl;

    return 0;
}