#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;

    int ao = 0, ta = 0;
    int run_ao = a, run_ta = d;
    int res_ao = c, res_ta = f;

    while (x > 0) {
        if (run_ao > 0) {
            run_ao--;
            ao += b;
        } else {
            if (res_ao == 1) {
                run_ao = a;
                res_ao = c;
            } else {
                res_ao--;
            }
        }

        if (run_ta > 0) {
            run_ta--;
            ta += e;
        } else {
            if (res_ta == 1) {
                run_ta = d;
                res_ta = f;
            } else {
                res_ta--;
            }
        }
        x--;
    }

    // cout << ao << " " << ta << endl;

    if (ao < ta) cout << "Aoki" << endl;
    else if (ao > ta) cout <<"Takahashi" << endl;
    else cout << "Draw" << endl;

    return 0;
}