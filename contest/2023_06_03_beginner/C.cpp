#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    vector<int> x(2004), y(2005);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x.at(i) >> y.at(i);

    vector<bool> ans(2005, false);
    ans.at(1) = true;

    queue<int> que;
    que.push(1);

    while (que.size()) {
        int p = que.front();
        que.pop();

        int px = x.at(p);
        int py = y.at(p); 

        for (int i = 1; i <= n; i++) {
            if (ans.at(i)) continue;

            int ix = x.at(i);
            int iy = y.at(i); 
            if ((px - ix) * (px - ix) + (py - iy) * (py - iy) <= d * d) {
                que.push(i);
                ans.at(i) = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans.at(i)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}