#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    string s;
    multiset<int> ms, ms_y;
    int cnt = 0;
    cin >> n >> k >> s;

    int all_x = 0;
    int fir = 0, end = 0, cle = 0;
    bool flag = (s.at(0) == 'X') ? true : false;
    bool y_flag = 0;
    int x = 0, ans = 0;
    int fir_y = 0, end_y = 0, cnt_y = 0;
    for (int i = 0; i < n ; i++) {
        if (s.at(i) == 'X') {
            if (!flag && x == 0) fir_y = ans + 1;
            x++;
            if (cnt_y != 0) ms_y.insert(cnt_y);
            cnt++;
            cnt_y = 0;
            y_flag = false;
        } else {
            if (y_flag) ans++;
            else y_flag = true;
            if (flag) { fir = cnt; flag = 0; }
            if (cnt != 0) ms.insert(cnt);
            cnt = 0;
            cnt_y++;
        }
    }

    if (cnt != 0)  { ms.insert(cnt); end = cnt; }

    for (int i = n-1; i >= 0; i--) {
        if (s.at(i) == 'Y') end_y++;
        else break;
    }

    if (fir == 0) cle++;
    if (end == 0) cle++;

    // cout << fir << " " << end;
    if (x == n) all_x = 1;

    if (k < x) {
        // cout <<1 << endl;
        while (k > 0) {
            int mini;
            int emp = 0;
            // cout << "size " << ms.size() << endl;
            if (!ms.empty()) {
                mini = *begin(ms);
                // cout << "Mini " << mini << endl;
            } else {
                emp = 1;
                mini = -1;
            }

            // cout << "cle " << cle << " " << emp <<endl;

            if ((mini == fir || mini == end) && cle != 2) {
                ms.erase(ms.find(mini));
                cle++;
                continue;
            }

            // cout << "ans " << ans << endl;

            if (emp == 1) {
                // cout << "emp " << endl;
                int edge_mini = min(fir, end);
                // cout << "emin " << edge_mini << endl;
                if (k >= edge_mini) {
                    k -= edge_mini;
                    ans += edge_mini;
                } else {
                    ans += k;
                    k = 0;
                }

                // if (k == 0) break;

                if (edge_mini == fir) edge_mini = end;
                else edge_mini = fir;

                if (k >= edge_mini) {
                    k -= edge_mini;
                    ans += edge_mini;
                } else {
                    ans += k;
                    k = 0;
                }
                if (all_x) ans--;
            } else {
                if (k >= mini) {
                    k -= mini;
                    ans += mini+1;
                } else {
                    ans += k;
                    k = 0;
                }
                ms.erase(ms.find(mini));
            }
        }
    } else {
        ans = n-1;
        k -= x;

        while (k > 0) {
            // cout << "ans " << ans << " k " << k << endl;
            if (fir_y != 0 || end_y != 0) {
                // cout << fir_y << " " << end_y << endl;
                int edge_mini = min(fir_y, end_y);
                if (k >= edge_mini) {
                    k -= edge_mini;
                    ans -= edge_mini;
                } else {
                    ans -= k;
                    k = 0;
                }

                if (edge_mini == fir_y) edge_mini = end_y;
                else edge_mini = fir_y;

                if (k >= edge_mini) {
                    k -= edge_mini;
                    ans -= edge_mini;
                } else {
                    ans -= k;
                    k = 0;
                }
                if (fir_y != 0) ms_y.erase(ms_y.find(fir_y));
                if (ans < 0) ans = 0;
                fir_y = 0; end_y = 0;
            } else {
                int maxi = *rbegin(ms_y);
                // cout << "ms_y_size " << ms_y.size() << " maxi " << maxi << endl;
                if (k <= maxi) {
                    ans -= k+1;
                    k = 0;
                } else {
                    ans -= maxi+1;
                    k -= maxi;
                }
                ms_y.erase(ms_y.find(maxi));
            }
        }
    }

    cout << ans << endl;

    return 0;
}