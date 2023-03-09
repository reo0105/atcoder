#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, maxi = 0;
    vector<int> a(105);
    set<int> sb;

    cin >> n >> k;
    for (int i = 0; i < n; i++) { cin >> a.at(i); maxi = max(maxi, a.at(i)); }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        sb.insert(b);
    }

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == maxi) {
            if (sb.count(i+1)) {
                flag = 0;
            }
        }
    }

    if (flag) cout << "No" << endl;
    else cout << "Yes" << endl;



    return 0;
}