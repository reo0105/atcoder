#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int n;
    vector<bool> prime(2000005, true);
    vector<vector<int>> ans(1005, vector<int>(1005));
    set<int> even;
    cin >> n;

    for (int i = 2; i <= n*n; i +=2) even.insert(i);

    for (int i = 2; i*i <= 2000003; i++) {
        if (prime.at(i)) {
            for (int j = i*2; j <= 2000003; j+=i) prime.at(j) = false;
        }
    }

    // for (int i : even) cout << i << " " ;

    // cout << "out" << endl;

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ans.at(i).at(j) = i*n*2+2*j+1;
            if (n % 2 == 0 && ans.at(i).at(j) == n*n-1) break;
            else if (n % 2 && ans.at(i).at(j) == n*n) break;
        }
        if (j != n) break;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << ans.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    // if (n == 3) {
    //     cout << 5 << " " << 9 << " " << 1 << endl;
    //     cout << 3 << " " << 7 << " " << 8 << endl;
    //     cout << 6 << " " << 2 << " " << 4 << endl;
    //     return 0;
    // }

    // set<int> done;
    if (n % 2 == 1) {
        if (j != n) {
            j++;
            // cout << i << " " << j << endl;
            int cnt = 0;
            for (int k = 2; k < n*n; k+=2) {
                if (!prime.at(ans.at(i-1).at(j)+k) && !prime.at(ans.at(i).at(j-1)+k) && even.count(k)) {
                    even.erase(k);
                    ans.at(i).at(j) = k;
                    cnt++;
                    break;
                }
            }

            // cout << cnt << endl;

            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         cout << ans.at(i).at(j) << " ";
            //     }
            //     cout << endl;
            // }

            for (j++; j < n; j++) {
                for (int k = 2; k < n*n; k+=2) {
                    if (!prime.at(ans.at(i-1).at(j)+k) && even.count(k)) {
                        ans.at(i).at(j) = k;
                        even.erase(k);
                        cnt++;
                        break;
                    }
                }
            }


            i++;
            // cout << i << " " << j << " " << cnt << endl;
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         cout << ans.at(i).at(j) << " ";
            //     }
            //     cout << endl;
            // }

            for (j = 0; j < n; j++) {
                for (int k = 2; k < n*n; k+=2) {
                    if (!prime.at(ans.at(i-1).at(j)+k) && even.count(k)) {
                        ans.at(i).at(j) = k;
                        even.erase(k);
                        cnt++;
                        break;
                    }
                }
                if (cnt == n) break;
            }

            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         cout << ans.at(i).at(j) << " ";
            //     }
            //     cout << endl;
            // }


            // cout << i << " " << j << endl;
            for (j++; j < n; j++) {
                int mini = *begin(even);
                ans.at(i).at(j) = mini;
                even.erase(mini);
            }

            for (i++; i < n; i++) {
                for (j = 0; j < n; j++) {
                    int mini = *begin(even);
                    ans.at(i).at(j) = mini;
                    even.erase(mini);
                }
            }
        }
    } else {
        i++;
        // cout << i << " " << j << endl;
        for (j = 0; j < n; j++) {
            for (int k = 2; k <= n*n; k+=2) {
                if (!prime.at(ans.at(i-1).at(j)+k) && even.count(k)) {
                    even.erase(k);
                    ans.at(i).at(j) = k;
                    break;
                } else if (k == n*n) {
                    ans.at(i).at(j) /= 0;
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << ans.at(i).at(j) << " ";
        //     }
        //     cout << endl;
        // }

        for (i++; i < n; i++) {
            for (j = 0; j < n; j++) {
                int mini = *begin(even);
                ans.at(i).at(j) = mini;
                even.erase(mini);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}