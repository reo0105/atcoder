#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> a;
    vector<int> b(100002);

    cin >> n;
    for (int i =0; i < n; i++) { 
        int x;
        cin >> x;
        a.push_back(make_pair(x, i)); 
    }

    sort(a.begin(), a.end());

    // for (int i = 0; i < n; i++) {
    //     cout << a.at(i).first << " " << a.at(i).second << endl;
    // }

    int pre = 0, index, cnt = 0;
    for (int i = 0; i < n; i++) {
        index = a.at(i).second;
        if (pre != a.at(i).first) {
            pre = a.at(i).first;
            cnt++;
        }
        b.at(index) = cnt;
    }

    for (int i = 0; i < n; i++) {
        cout << b.at(i) << " ";
    }
    cout << endl;

    
    return 0;
}