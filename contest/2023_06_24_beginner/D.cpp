#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> ans(200005, 0);
    stack<int> fir;

    for (int i = 0; i < n; i++) {
        if (s.at(i) == '(') fir.push(i);
        else if (s.at(i) == ')') {
            if (fir.empty()) continue;

            int x = fir.top();
            fir.pop();
            ans.at(x)++;
            ans.at(i+1)--;
        }
    }

    for (int i = 0; i < n; i++) ans.at(i+1) += ans.at(i);

    for (int i = 0; i < n; i++) {
        if (ans.at(i) >= 1) continue;
        else cout << s.at(i);
    }


    return 0;
}