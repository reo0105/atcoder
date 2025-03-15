#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;

    s.push_back('1');
    for (int i = 1; i <= n; i++) {
        int j;
        for (j = 1; j < 10; j++) {
            if (n % j == 0 && i % (n/j) == 0) {
                s.push_back('0' + j);
                break;
            }
        }
        if (j == 10) s.push_back('-');
    }

    cout << s << endl;

    return 0;
}