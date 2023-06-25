#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int n;
    vector<int> a(100005, 0);
    vector<int> ans;

    cin >> n;
    for (int i = 0; i < 3*n; i++) {
        int x;
        cin >> x;
        if (a.at(x) == 1) ans.push_back(x);
        a.at(x)++; 
    }

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}