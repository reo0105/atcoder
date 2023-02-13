#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a, n;
    int lim = 1000000;
    vector<int> mini(1000005, -1);

    cin >> a >> n;

    queue<int> que;
    que.push(1);
    mini.at(1) = 0;

    while (!que.empty()) {
        ll now = que.front();
        que.pop();

        ll next = now * a;
        if (next < lim) {
            if (mini.at(next) == -1) {
                mini.at(next) = mini.at(now) + 1;
                que.push(next);
            }
        } 
        if (now >= 10 && now % 10 != 0) {
            // int num = 100;
            // while (now / num > 0) num *= 10;
            // num /= 10;
            // int nx = (now % 10) * num + (now / 10);
            string s = to_string(now);
            string t;
            t.push_back(s.at(s.size()-1));
            t.append(s.substr(0, s.size()-1));
            int nx = stoi(t);

            if (nx < lim) {
                if (mini.at(nx) == -1) {
                    mini.at(nx) = mini.at(now) + 1;
                    que.push(nx);
                }
            } 
        }

        if (mini.at(n) != -1) break;
    }

    cout << mini.at(n) << endl;

    return 0;
}