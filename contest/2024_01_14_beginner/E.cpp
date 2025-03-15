#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[16][2][130][130];

int main()
{
    ll n;
    cin >> n;
    n++;

    vector<int> digit;
    while (n) {
        digit.push_back(n%10);
        n /= 10;
    }

    reverse(digit.begin(), digit.end());
    int m = (int)digit.size();

    ll ans = 0;

    for (int k = 1; k <= 126; k++) {
        for (int i = 0; i < m+1; i++) {
            for (int j = 0; j < 2; j++) {
                for (int s = 0; s < k+1; s++) {
                    for (int r = 0; r < k; r++) {
                        dp[i][j][s][r] = 0;
                    }
                }
            }
        }

        dp[0][0][0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
                for (int s = 0; s < k+1; s++) {
                    for (int r = 0; r < k; r++) {
                        for (int d = 0; d < 10; d++) {
                            int ni = i+1;
                            int nj = j;
                            int ns = s+d;
                            int nr = (r*10+d)%k;

                            if (ns > k) continue;
                            if (j == 0) {
                                if (digit[i] < d) continue;
                                if (digit[i] > d) nj = 1;
                            }

                            dp[ni][nj][ns][nr] += dp[i][j][s][r];
                        }
                    }
                }
            }
        }

        ans += dp[m][1][k][0];
    }

    cout << ans << endl;
    
    return 0;
}