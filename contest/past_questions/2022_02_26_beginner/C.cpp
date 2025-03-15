#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, flag = 0;
    vector<string> s(1005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt0 = 0, cnt1 = 0;
            for (int k = 0; k < 6; k++) { //tate
                if (i+5 < n) {
                    if (s.at(i+k).at(j) == '#') cnt0++;
                }

                if (i-5 >= 0) {
                    if (s.at(i-k).at(j) == '#') cnt1++;
                }
            }
            if (cnt0 >= 4 || cnt1 >= 4) {
                flag = 1;
                goto out;
            }

            cnt0 = 0; cnt1 = 0;

            for (int k = 0; k < 6; k++) { //yoko
                if (j+5 < n) {
                    if (s.at(i).at(j+k) == '#') cnt0++;
                }

                if (j-5 >= 0) {
                    if (s.at(i).at(j-k) == '#') cnt1++;
                }
            }
            if (cnt0 >= 4 || cnt1 >= 4) {
                flag = 1;
                goto out;
            }

            cnt0 = 0; cnt1 = 0;
            int cnt2 = 0, cnt3 = 0;

            for (int k = 0; k < 6; k++) { //naname
                if (i-5 >= 0 && j+5 < n) {
                    if (s.at(i-k).at(j+k) == '#') cnt0++;
                }

                if (i-5 >= 0 && j-5 >= 0) {
                    if (s.at(i-k).at(j-k) == '#') cnt1++;
                }

                if (i+5 < n && j-5 >= 0) {
                    if (s.at(i+k).at(j-k) == '#') cnt2++;
                }

                if (i+5 < n && j+5 < n) {
                    if (s.at(i+k).at(j+k) == '#') cnt3++;
                }
            }
            if (cnt0 >= 4 || cnt1 >= 4 || cnt2 >= 4 || cnt3 >= 4) {
                flag = 1;
                goto out;
            }
        }
    }

out:

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}