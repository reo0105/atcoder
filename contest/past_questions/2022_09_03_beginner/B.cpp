#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int flag = 0;

    vector<int> rem(10, 0);
    vector<int> id = {4, 3, 5, 2, 4, 6, 1, 3, 5, 7};

    for (int i = 0; i < 10; i++) {
        if (s.at(i) == '1') rem.at(id.at(i))++;
    }


    if (s.at(0) == '0') {
        for (int i = 1; i <= 7; i++) {
            if (rem.at(i) != 0) {
                for (int j = i+1; j <= 7; j++) {
                    if (rem.at(j) == 0) {
                        for (int k = j+1; k <= 7; k++) {
                            if (rem.at(k) != 0) {
                                flag = 1;
                                goto out;
                            }
                        }
                    }
                }
            }
        }
    }

out:
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}