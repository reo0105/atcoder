#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> a(105);
    stack<int> stk;

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a.at(i);

    int cnt = 0, num = 0;
    for (int i = 1; i <= n; i++) {
        if (a.at(cnt) == i) {
            stk.push(i);
            cnt++;
        } else {
            cout << i << " ";
            while(!stk.empty()) {
                int t = stk.top();
                cout << t << " ";
                stk.pop();
            }
        }
    }

    cout << endl;


    return 0;
}