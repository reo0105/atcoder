#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a;

    cin >> n;
    for (int i = 0; i < 5*n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = n; i < 4*n; i++) {
        cnt += a.at(i);
    } 


    double ans = (double)cnt / (double)(3*n);

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}