#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(2005);
    for (int i = 0; i < n; i++) cin >> s.at(i);

    int q;
    cin >> q;

    vector<vector<int>> a(2005, vector<int>(2005));
    vector<vector<int>> b(2005, vector<int>(2005));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s.at(i).at(j) == 'X') continue;

            a.at(i).at(j)++;
            a.at(min(i+m, n)).at(j)--;
            // (i + m, j) + (-1, 2)x  (l <= x <= r)
            int l = max(0, i+m-n); // i + m - x <= n
            int r = min(m, (n-j) / 2); // j + 2x <= n

            if (l < r) {
                b.at(i+m-l).at(j+2*l)++;
                b.at(i+m-r).at(j+2*r)--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.at(i+1).at(j) += a.at(i).at(j);
            b.at(i+1).at(j) += b.at(i).at(j+2);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.at(i).at(j) += b.at(i).at(j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.at(i).at(j+1) += a.at(i).at(j);
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << a.at(x).at(y) << endl;
    }

    return 0;
}