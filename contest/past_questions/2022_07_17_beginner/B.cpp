#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int x, y, z, n;

    vector<bool> ans(1005, false);
    vector<int> a(1005), b(1005);
    vector<int> sum(1005);

    cin >> n >> x >> y >> z;

    for (int i = 1; i <= n; i++) cin >> a.at(i);
    for (int i = 1; i <= n; i++) cin >> b.at(i);
    for (int i = 1; i <= n; i++) sum.at(i) = a.at(i) + b.at(i);

    for (int i = 0; i < x; i++) {
        int maxi = -1, index = -1;
        for (int j = 1; j <= n; j++) {
            if (a.at(j) > maxi && ans.at(j) == false) {
                maxi = a.at(j);
                index = j;
            }
        }
        ans.at(index) = true;
    }

    for (int i = 0; i < y; i++) {
        int maxi = -1, index = -1;
        for (int j = 1; j <= n; j++) {
            if (b.at(j) > maxi && ans.at(j) == false) {
                maxi = b.at(j);
                index = j;
            }
        }
        ans.at(index) = true;
    }

    for (int i = 0; i < z; i++) {
        int maxi = -1, index = -1;
        for (int j = 1; j <= n; j++) {
            if (sum.at(j) > maxi && ans.at(j) == false) {
                maxi = sum.at(j);
                index = j;
            }
        }
        ans.at(index) = true;
    }

    for (int i = 1; i <= n; i++) {
        if (ans.at(i)) cout << i << endl;
    }


    return 0;
}