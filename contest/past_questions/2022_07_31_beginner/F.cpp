#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int n, k, t;
    cin >> n >> k;
    t = k;

    vector<int> p(200005);
    for (int i = 0; i < n; i++) cin >> p.at(i);

    int mini = 1e9, index;
    for (int i = 0; i <= k; i++) {
        if (mini > p.at(i)) {
            mini = p.at(i);
            index = i;
        }
    }

    stack<int> stk;
    int cnt = index;

    stk.push(p.at(index));
    t -= index;
    for (int i = index+1; i < n; i++) {
        while (t > 0 && stk.top() > p.at(i)) {
            stk.pop();
            t--;
        }
        stk.push(p.at(i));
    }

    while (t > 0) {
        stk.pop();
        t--;
    }

    vector<int> ans;
    while (stk.size()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());

    mini = 1e9;
    int index1 = -1;
    stack<pi> stkp;

    for (int i = n-1; i > n-1-k; i--) {
        if (mini > p.at(i)) {
            mini = p.at(i);
            index1 = i;
        }
    }

    if (index1 != -1) {
        vector<pi> rot;
        cnt = n-index1;
        for (int i = 0; i < n; i++) {
            if (i+index1 < n) rot.push_back(make_pair(p.at(i+index1), 0));
            else rot.push_back(make_pair(p.at((i+index1)%n), 1));
        }

        // for (int i = 0; i < n; i++) {
            // cout << rot.at(i).first << " " << rot.at(i).second << endl;
        // }

        stkp.push(make_pair(p.at(index1), 0));
        k -= cnt;

        // cout << index1 << " " << k << " " << cnt << endl;
        for (int i = 1; i < n; i++) {
            while (stkp.size() && (stkp.top().second == 0 || k > 0) && stkp.top().first > rot.at(i).first) {
                if (stkp.top().second == 1) k--;
                stkp.pop();
            }
            stkp.push(make_pair(rot.at(i).first, rot.at(i).second));
        }
        // cout << k << endl;

        while (k > 0) {
            stkp.pop();
            k--;
        }

        vector<int> ans1;
        while (stkp.size()) {
            ans1.push_back(stkp.top().first);
            stkp.pop();
        }
        reverse(ans1.begin(), ans1.end());

        ans = min(ans, ans1);
    }
    
    for (int x : ans) cout << x << " ";

    return 0;
}