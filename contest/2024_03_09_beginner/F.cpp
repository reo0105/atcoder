#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[80][80][80*80]

int main() {
    int n;
    cin >> n;

    vector<vector<int>> p(n, vector<int>(n));
    vector<vector<int>> r(n, vector<int>(n-1));
    vector<vector<int>> d(n-1, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            cin >> r[i][j];
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    

    return 0;
}