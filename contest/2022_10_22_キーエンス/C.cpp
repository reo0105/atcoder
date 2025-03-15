#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> data(200002);
    vector<pair<int, int>> num(400002, make_pair(0, 0));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> data.at(i);
    }

    for (int i = 1; i <= n; i++) {
        int x = 2*i, y = 2*i+1;
        int def = num.at(data.at(i)).second + 1;
        num.at(x) = make_pair(x, def);
        num.at(y) = make_pair(y, def);
    }

    for (int i = 1; i <= 2*n+1; i++) {
        cout << num.at(i).second << endl;
    }
    
    return 0;
}