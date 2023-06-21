#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(1005);


    while (1) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> a.at(i);

        int cnt = 0;
        for (int i = 1; i <= n-2; i++) {
            if (a.at(i-1) < a.at(i) && a.at(i) > a.at(i+1)) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}