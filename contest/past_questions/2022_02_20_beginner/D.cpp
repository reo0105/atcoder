#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;

    cin >> n;

    stack<p> stc;
    int a, cnt = 0;
    cin >> a;
    stc.push(make_pair(a, 1));
    cout << ++cnt << endl;

    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        p t;
        if (!stc.empty()) t = stc.top();
        else {
            stc.push(make_pair(a, 1));
        }
        if (t.first == a) {
            t.second++;
            cnt++;
            stc.pop();
            if (t.second != a) {
                stc.push(make_pair(a, t.second)); 
            } else {
                cnt -= t.second;
            }
        } else {
            stc.push(make_pair(a, 1));
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}