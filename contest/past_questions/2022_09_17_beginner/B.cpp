#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s(12);

    for (int i = 1; i <= 10; i++) cin >> s.at(i);

    int a, b, c, d = -1;

    int flag = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (flag == 0 && s.at(i).at(j-1) == '#') {
                flag = 1;
                c = j;
                a = i;
            }
            if (flag && s.at(i).at(j-1) == '.') {
                d = j-1;
                goto out;
            }
            if (flag && j == 10) {
                d = j;
                goto out;
            }
        }
    }
out:
    for (int i = a; i <= 10; i++) {
        if (s.at(i).at(c-1) == '.') {
            b = i-1;
            break;
        }
        if (i == 10) b = 10;
    }

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    return 0;
}