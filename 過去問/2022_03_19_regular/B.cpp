#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n;
    vector<int> a(300005, 0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) x = -1;
        else x = 1;
        a.at(i) = x;
        a.at(i) += a.at(i-1);
    }

    int maxi = 0, mini = 0, sl_maxi = 0, sl_mini = 0;

    for (int i = 1; i <= n; i++) {
        if (sl_maxi < a.at(i)) sl_maxi = a.at(i);
        if (sl_mini > a.at(i)) sl_mini = a.at(i);

        maxi = max(maxi, a.at(i)-sl_mini);
        mini = min(mini, a.at(i)-sl_maxi);
    } 

    cout << maxi - mini + 1 << endl;    

    return 0;
}