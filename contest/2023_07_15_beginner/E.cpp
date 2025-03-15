#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int zero = 0, one = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if (x == 0) {
            one += zero;
            zero = 1;
        } else {
            swap(zero, one);
            one++;
        }
        ans += one;
    }

    cout << ans << endl;

    return 0;
}