#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[16][2][130][130];

int main()
{
    ll n;
    cin >> n;
    n++;

    vector<int> digits;
    while (n) {
        digits.push_back(n%10);
        n /= 10;
    }

    reverse(digits.begin(), digits.end());
    int ks = (int)digits.size();

    ll ans = 0;

    // for (int k = 1; k <= 126; k++) {
        for (int i = 0; i < ks+1; i++) {
            for (int j = 0; j < 2; j++) {
                for (int s = 0; s < 127; s++) {
                    for (int r = 0; r < 126; r++) {
                        dp[i][j][s][r] = 0;
                    }
                }
            }
        }

        dp[0][0][0][0] = 1;
        for (int i = 0; i < ks; i++) {
            for (int j = 0; j < 2; j++) {
                for (int s = 0; s < 127; s++) { // from
                    for (int k = 1; k < 127; k++){ // to
                        for (int r = 0; r < 126; r++) {
                            for (int d = 0; d < 10; d++) {
                                int ni = i+1;
                                int nj = j;
                                int ns = s+d;
                                int nr = (r*10+d)%k;

                                if (ns > k) continue;
                                if (j == 0) {
                                    if (digits[i] < d) continue;
                                    if (digits[i] > d) nj = 1;
                                }

                                dp[ni][nj][ns][nr] += dp[i][j][s][r];
                            }
                        }
                    }
                }
            }
        }
    // }

    for (int i = 1; i < 127; i++) ans += dp[ks][1][i][0];

    cout << ans << endl;
}