#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    vector<pii> ans;

    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n-8; i++) {
        for (int j = 0; j < m-8; j++) {
            int ok = 1;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (s[i+k][j+l] != '#') ok = 0;
                }
            }

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (s[i+k+6][j+l+6] != '#') ok = 0;
                }
            }

            for (int k = 0; k < 3; k++) {
                if (s[i+3][j+k] != '.') ok = 0;
            }

            for (int k = 0; k < 4; k++) {
                if (s[i+k][j+3] != '.') ok = 0;
            }

            for (int k = 0; k < 3; k++) {
                if (s[i+5][j+k+6] != '.') ok = 0;
            }

            for (int k = 0; k < 4; k++) {
                if (s[i+k+5][j+5] != '.') ok = 0;
            }

            if (ok) ans.push_back(make_pair(i, j));
        }
    }

    for (pii p : ans) {
        cout << p.first+1 << " " << p.second+1 << endl;
    }

    return 0;
}