#include <bits/stdc++.h>
using namespace std;

vector<int> a(200005);
vector<int> dist(200005, -1);
stack<int> stk;
int cnt = 1;
int endp;
vector<int> ans;

void dfs(int from)
{
    stk.push(from);
    dist.at(from) = cnt;

    if (dist.at(a.at(from)) == cnt) {
        endp = a.at(from);
        int sz = 0;
        int now;
        while (1) {
            sz++;
            if (stk.top() == endp) break;
            else {
                now = stk.top();
                ans.push_back(now);
                stk.pop();
            }
        }

        ans.push_back(endp);
        cout << sz << endl;
        for (int i = sz-1; i >= 0; i--) cout << ans.at(i) << " ";
        cout << endl;
        exit(0);
    }

    dfs(a.at(from));

    stk.pop();
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a.at(i);

    for (int i = 1; i <= n; i++) {
        if (dist.at(i) == -1) {
            dfs(i);
            cnt++;
        }
    }

    return 0;
}