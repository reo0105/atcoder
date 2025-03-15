#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> plus, minus;
    vector<int> X;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        // if (x > 0) plus.push_back(x);
        // else minus.push_back(x);
        X.push_back(x);
    }

    // sort(plus.begin(), plus.end());
    // sort(minus.rbegin(), minus.rend());

    sort(X.begin(), X.end());
    
    // int pn = (int)plus.size();
    // int mn = (int)minus.size();

    // double mini, maxi;
    // if (mn >= 3) {
    //     for (int i = 0; i < 3; i++) {
    //         mini += minus.at(i);
    //     }
    // } else {
    //     for (int i = 0; i < mn; i++) {
    //         mini += minus.at(i);
    //     }
    //     for (int i = 0; i < 3-mn; i++) {
    //         mini += plus.at(i);
    //     }

    //     if (mini > 0) {
    //         mini = 0;
    //         for (int i = pn-1; i >= 0; i--) {
    //             mini += plus.at(i);
    //         }
    //         if (pn < 3) {
    //             for (int i = 0; i < 3-pn; i++) {
    //                 mini += minus.at(i);
    //             }
    //         }

    //     }
    // }

    double mini = 1e9, maxi = -1e9;
    for (int j = 1; j < n-1; j++) {
        double x, y, z;
        double t;
        y = X.at(j);

        x = X.at(0); z = X.at(n-1);
        t = (x+y+z) / (x*y*z);
        mini = min(t, mini);
        maxi = max(t, maxi);
        x = X.at(j-1); z = X.at(n-1);
        t = (x+y+z) / (x*y*z);
        mini = min(t, mini);
        maxi = max(t, maxi);
        x = X.at(0); z = X.at(j+1);
        t = (x+y+z) / (x*y*z);
        mini = min(t, mini);
        maxi = max(t, maxi);
        x = X.at(j-1); z = X.at(j+1);
        t = (x+y+z) / (x*y*z);
        mini = min(t, mini);
        maxi = max(t, maxi);
    }

    cout << fixed << setprecision(16) << mini << " " << maxi << endl;

    return 0;
    
}