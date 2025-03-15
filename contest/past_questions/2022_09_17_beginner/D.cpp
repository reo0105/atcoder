#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n;
    set<p> s;
    vector<int> dir_x = {-1, -1, 0, 0, 1, 1};
    vector<int> dir_y = {-1, 0, -1, 1, 0, 1};

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    int ans = 0;
    while (s.size()) {
        queue<p> que;
        p u = *begin(s);
        que.push(u);
        ans++;

        while (que.size()) {
            u = que.front();
            s.erase(u);
            que.pop();
            int x = u.first;
            int y = u.second;

            // cout << x << " " << y << endl;

            for (int i = 0; i < 6; i++) {
                int nx = x + dir_x.at(i);
                int ny = y + dir_y.at(i);

                // cout << "next " << nx << " " << ny << endl;

                if (s.count(make_pair(nx, ny))) {
                    // cout << "erase " << endl;
                    que.push(make_pair(nx, ny));
                    s.erase(make_pair(nx, ny));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}