#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // vector<vector<int>> G()

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> G(n+1);

        for (int j = 0; j < n-1; j++) {
            int a, b;
            cin >> a >> b;
            G.at(a).push_back(b);
            G.at(b).push_back(a);
        }
        string s;
        cin >> s;

        queue<int> ones;
        for (int j = 1; j <= n; j++) {
            if ((int)G.at(j).size() == 1) ones.push(j);
        }

        vector<char> color(n+1, '-');
        vector<int> done(n+1, false);

        queue<int> pars;

        while (ones.size()) {
            int u = ones.front();
            ones.pop();
            int p;// = G.at(u).at(0);
            for (int x : G.at(u)) {
                if (done.at(x)) continue;
                p = x;
            }
            done.at(u) = true;


            if (color.at(p) == '-') { color.at(p) = s.at(u-1); pars.push(p); }
            else if (color.at(p) != s.at(u-1)) {
                cout << -1 << endl;
                return 0;
            }
        }

        queue<int> pp;
        while (pars.size()) {
            int u = pars.front();
            int p = -1;
            pars.pop();

            for (int x : G.at(u)) {
                if (done.at(x)) {
                    color.at(x) = s.at(u-1);
                } else {
                    p = x;
                }
            }
            done.at(u) = true;
            if (p == -1 || color.at(p) != '-') continue;
            pp.push(p);
        }

        while (pp.size()) {
            int u = pp.front();
            int p = -1;
            pp.pop();

            int b = 0, w = 0;
            for (int x : G.at(u)) {
                if (color.at(x) == 'B') b++;
                else if (color.at(x) == 'W') w++;
                else p = x;
            }

            if (p == -1 || color.at(p) != '-') continue;

            if (b > w && s.at(u-1) == 'W') {
                cout << -1 << endl;
                return 0;
            } else if (b < w && s.at(u-1) == 'B') {
                cout << -1 << endl;
                return 0;
            }

            if (b == w && s.at(u-1) == 'B') color.at(u) = 'B';
            else if (b == w) color.at(u) = 'W';
            else if (b > w) color.at(u) = 'B';
            else color.at(u) = 'W';
            // if (s.at(p-1) == 'B') color.at(u) = 'B';
            // else color.at(u) = 'W';
            pp.push(p);

            // if (b == w) continue;
            // else if (b > w) color.at(p-1) = 'B';
            // else color.at(p-1) = 'W';
                        
        }

        for (int i = 1; i <= n; i++) {
            if (color.at(i) != '-') cout << color.at(i);
            else {
                cout << 'B';
            }
        }
        cout << '\n';

    }

    return 0;
}