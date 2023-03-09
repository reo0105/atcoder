#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h1, h2, h3, w1, w2, w3;
    int ans = 0;

    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    for (int a1 = 1; a1 <= h1-2; a1++) {
        for (int a3 = 1; a3 <= h1-a1-1; a3++) {
            for (int a7 = 1; a7 <= h3-2; a7++) {
                for (int a9 = 1; a9 <= h3-a7-1; a9++) {
                    int a2 = h1 - a1 - a3;
                    int a8 = h3 - a7 - a9;
                    int a4 = w1 - a1 - a7;
                    int a5 = w2 - a2 - a8;
                    int a6 = w3 - a3 - a9;
                    if (a4 > 0 && a5 > 0 && a6 > 0 && a2 > 0 && a6 > 0 && a4+a5+a6==h2) ans++;
                }
            }
        }
    }

    cout << ans << endl;


    return 0;
}