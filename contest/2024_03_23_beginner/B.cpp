#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, b;
    cin >> w >> b;

    string s = "wbwbwwbwbwbw";

    int ok = 0;
    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        int ni = i;
        int cnt_w = 0;
        int cnt_b = 0;
        while (1) {
            if (ni == n) ni = 0;

            if (s[ni] == 'w') cnt_w++;
            else cnt_b++;

            ni++;

            if (cnt_w > w || cnt_b > b) break;
            if (cnt_w == w && cnt_b == b) {
                ok = 1;
                break;
            }

        }

        if (ok) {
            cout << "Yes" << endl;
            return 0; 
        }
    }

    cout << "No" << endl;

    return 0;
}