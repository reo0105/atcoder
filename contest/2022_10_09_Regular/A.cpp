#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dim(10, -1);
    int num;
    string ans;

    for (int j = 1; j <= 9; j++) {
        ll tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp = (tmp*10 + j) % m;
            if (tmp == 0) {
                dim.at(j) = i;
            }
        }
    }

    int d = 0;
    for (int j = 1; j <= 9; j++) {
        if (dim.at(j) >= d) {
            d = dim.at(j);
            num = j;
        }
    }

    if (d == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < d; i++) ans.push_back('0' + num);

    cout << ans << endl;

    return 0;
}