#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> S;
set<string> t;

void dfs(int id, int rem, string ans)
{
    if (rem < 0) return;

    if (id == (int)S.size()) { 
        if ((int)ans.size() >= 3 && !t.count(ans)) {
            cout << ans << endl;
            exit(0);
        }

        return;
    }

    if ((int)ans.size() != 0 && ans.back() != '_') {
        dfs(id, rem, ans + '_');
    } else {
        dfs(id+1, rem, ans + S.at(id));
        if ((int)ans.size() != 0) dfs(id, rem-1, ans+'_');
    }
}

int main()
{
    int n, m;
    int len = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        S.push_back(s);
        len += (int)s.size();
    }

    sort(S.begin(), S.end());

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        t.insert(tmp);
    }

    do {

        dfs(0, 16-len-(n-1), "");
    
    } while (next_permutation(S.begin(), S.end()));

    cout << -1 << endl;

    return 0;
}