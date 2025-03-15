#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, cnt = 0, flag = 1;
    vector<int> a(200002);
    vector<int> dp(200002);

    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    
    dp.at(0) = n / 2;

    for (int i = 1; i <= n; i++) {
        if (dp.at(i-1) <= 0 && a.at(i) == 2) {
            flag = 0;
            break;
        }
        if (a.at(i) == 2) {
            dp.at(i) = (l - 3) / 2;
            l-=3;
        } else {
            dp.at(i) =  (l - 2) / 2;
            l-=2;
        }
    }

    if (n == 1 && l == 2) {
        cout << "Yes" << endl;
    }else if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}