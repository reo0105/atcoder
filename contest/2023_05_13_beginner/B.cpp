#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int flag = 0;
    vector<int> a(105);
    vector<int> ans;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    for (int i = 0; i < n-1; i++) {
        if (abs(a.at(i) - a.at(i+1)) == 1) {
            ans.push_back(a.at(i));
        } else if (a.at(i) > a.at(i+1)) {
            for (int j = a.at(i); j > a.at(i+1); j--) ans.push_back(j);
        } else {
            for (int j = a.at(i); j < a.at(i+1); j++) ans.push_back(j);
        }
    }
    ans.push_back(a.at(n-1));

    for (int i = 0; i < (int)ans.size(); i++) cout << ans.at(i) << " ";
    cout << endl;

    return 0;
}