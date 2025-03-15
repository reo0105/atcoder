#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    vector<int> x(4), y(4);

    for (int i = 0; i < 4; i++) cin >> x.at(i) >> y.at(i);

    int flag = 1;
    for (int i = 0; i < 4; i++) {
        int a = x.at(i) - x.at((i+1)%4);
        int b = y.at(i) - y.at((i+1)%4);
        int c = x.at((i+2)%4) - x.at((i+1)%4);
        int d = y.at((i+2)%4) - y.at((i+1)%4);

        // cout << a << " " << b << " " << c << " " << d << endl;
        if (b*c-a*d <= 0) flag = 0;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}