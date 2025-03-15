#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int sz_s = (int)s.size();
    int sz_t = (int)t.size();

    queue<int> que;
    vector<int> done(n, false);

    for (int i = 0; i < sz_s-sz_t+1; i++) {
        int cnt = 0;
        for (int j = 0; j < sz_t; j++) {
            if (s[i+j] != t[j]) break;
            cnt++;
        }
        if (cnt == sz_t) {
            done[i] = true;
            for (int j = 0; j < sz_t; j++) s[i+j] = '?';

            for (int j = max(0, i-sz_t+1); j <= i-1; j++) que.push(j);
            for (int j = i+1; j <= min(sz_s, i+sz_t-1); j++) que.push(j);
        }
    }

    while (que.size()) {
        int start = que.front();
        que.pop();

        if (done[start]) continue;
        if (start >= sz_s-sz_t+1) continue;

        int cnt = 0;
        for (int j = 0; j < sz_t; j++) {
            if (s[start+j] != '?' && s[start+j] != t[j]) break;
            cnt++;
        }

        if (cnt == sz_t) {
            done[start] = true;
            for (int j = 0; j < sz_t; j++) s[start+j] = '?';

            for (int j = max(0, start-sz_t+1); j <= start-1; j++) que.push(j);
            for (int j = start+1; j <= min(sz_s, start+sz_t-1); j++) que.push(j);
        }
    }

    if (s == string(n, '?')) cout << "Yes" << endl;
    else cout << "No" << endl;    

    return 0;
}