#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "atcoder";
    map<char, int> mp;

    int cnt = 1;
    for (int x : s) {
        mp[x] = cnt++;
    }

    string t;
    cin >> t;

    vector<int> a;
    for (int i = 0; i < 7; i++) {
        a.push_back(mp[t.at(i)]);
    }

    int ans = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = i+1; j < 7; j++) {
            if (a.at(i) > a.at(j)) ans++;
        }
    }

    cout << ans << endl;


    return 0; 
}
