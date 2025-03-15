#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = (1<<m)-1; i > 0; i--) {
        int cnt = 0;
        for (int j = m-1; j >= 0; j--) {
            if ((i>>j) & 1 == 1) cnt++;
        }
        if (cnt == n) {
            for (int j = m-1; j >= 0; j--) {
                if ((i>>j) & 1 == 1) {
                    cout << m - j << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}