#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h1, h2, h3, w1, w2, w3;
    int ans = 0;

    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    for (int a = 1; a <= 28; a++) {
        for (int b = 1; b <= 28; b++) {
            if (a + b >= h1) break;
            
            for (int c = 1; c <= 28; c++) {
                for (int d = 1; d <= 28; d++) {
                    if (c + d >= h2) break;

                    int e = h1-a-b;
                    int f = h2-c-d;
                    int g = w1-a-c;
                    int h = w2-b-d;
                    int i = h3-g-h;

                    if (g > 0 && h > 0 && i > 0 && e+f+i == w3 && g+h+i == h3) ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0; 
}