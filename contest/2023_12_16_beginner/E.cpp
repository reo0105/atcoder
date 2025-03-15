#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int n;
    cin >> n;

    vector<stack<int>> portion(n+1);
    vector<int> use(n+1, 0);
    vector<int> ans(n+1, 0);

    vector<int> t(n+1), x(n+1);
    for (int i = 1; i <= n; i++) cin >> t[i] >> x[i];

    for (int i = 1; i <= n; i++) {

        if (t[i] == 1) {
            portion[x[i]].push(i);
        } else {
            if (portion[x[i]].empty()) {
                cout << -1 << endl;
                return 0;
            } else {
                int temp = portion[x[i]].top();
                portion[x[i]].pop();
                ans[temp] = 1;
                use[temp] += 1;
                use[i] -= 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        use[i+1] += use[i];
    }

    int maxi = 0;
    for (int i = 1; i <= n; i++) maxi = max(maxi, use[i]);

    cout << maxi << endl;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1 && ans[i]) cout << 1 << " ";
        else if (t[i] == 1) cout << 0 << " ";
    }
    cout << endl;


    return 0;

}