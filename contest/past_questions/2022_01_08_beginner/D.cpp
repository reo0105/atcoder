#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    vector<int> p(500005);
    priority_queue<int, vector<int>, greater<int>> que;
    set<int> cnt;

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p.at(i);

    for (int i = 0; i < k; i++) {
        que.push(p.at(i));
        cnt.insert(p.at(i));
    }

    int now = que.top();
    que.pop();
    cout << now << endl;
    for (int i = 0; i < n-k; i++) {
        if (p.at(k+i) > now) {
            que.push(p.at(k+i));
            now = que.top();
            que.pop();
        }
        cout << now << endl;
    }



    return 0;
}