#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string ans;
    int num = -1, k = -1;
    vector<int> rem(12, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            rem.at(j) = (rem.at(j) * 10 + j) % m;
            if (rem.at(j) == 0) {
                num = j;
                k = i+1;
            }
        }
    }

    if (num == -1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < k; i++) ans.push_back('0'+num);

    cout << ans << endl;

    return 0;
}