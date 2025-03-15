#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(20);
vector<bool> seen(20, false);
int ans = 0;

void dfs(int n, int tmp)
{
    int fir;
    for (fir = 0; fir < n; fir++) {
        if (!seen.at(fir)) break;
    }

    if (fir == n) ans = max(ans, tmp);

    seen.at(fir) = true;

    for (int sec = fir+1; sec < n; sec++) {
        if (!seen.at(sec)) {
            int tmp2 = tmp ^ a.at(fir).at(sec-1-fir);
            seen.at(sec) = true;
            dfs(n, tmp2);
            seen.at(sec) = false;
        }
    }

    seen.at(fir) = false;
}

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = i+1; j < 2*n; j++) {
            int x;
            cin >> x;
            a.at(i).push_back(x);
            // cout << x << " ";
        }
        // cout << endl;
    }

    int n2 = n*2;

    dfs(n2, 0);

    cout << ans << endl;

    return 0;
}