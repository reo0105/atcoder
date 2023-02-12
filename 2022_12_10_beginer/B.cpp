#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ok = 1;
    string s;

    cin >> s;
    if ((int)s.size() != 8) {
        ok = 0;
        goto end;
    } 
    if (!('A' <= s.at(0) && s.at(0) <= 'Z')) {
        ok = 0;
        goto end;
    }

    for (int i = 1; i < 7; i++) {
        if (i > 6) {
            ok = 0;
            goto end;
        } else {
            if (i == 1) {
                if (!('1' <= s.at(i) && s.at(i) <= '9')) {
                    ok = 0;
                    goto end;
                }
            } else {
                if (!('0' <= s.at(i) && s.at(i) <= '9')) {
                    ok = 0;
                    goto end;
                }
            }
        }
    }

    if (!('A' <= s.at(7) && s.at(7) <= 'Z')) {
        ok = 0;
        goto end;
    }

end:
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}