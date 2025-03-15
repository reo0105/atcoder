#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;

    stack<ll> stk;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        stk.push(a);

        if ((int)stk.size() < 2) continue;


        while (1) {
            int first = stk.top();
            stk.pop();
            int second = stk.top();
            // cout << i << " " << first << " " << second << endl;
            if (first == second) {
                stk.pop();
                if (stk.size()) second = stk.top();
                stk.push(first+1);
                first = first+1;
                if (stk.size() < 2) break;
            } else {
                stk.push(first);
                break;
            }
        }
    }

    cout << stk.size() << endl;

    return 0;
}