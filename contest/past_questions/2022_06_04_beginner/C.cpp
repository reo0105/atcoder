#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, k;
    vector<vector<int>> a(200005);
    vector<int> b;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.at(i%k).push_back(x); 
        b.push_back(x);
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < k; i++) {
        // int len = (int)a.at(i).size();
        // for (int j = 0; j < len-1; j++) {
            // if (a.at(i).at(j) > a.at(i).at(j+1)) swap(a.at(i).at(j), a.at(i).at(j+1));
        sort(a.at(i).begin(), a.at(i).end());
        // }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) ans.push_back(a.at(i%k).at(i/k));

    if (ans == b) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}