#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();
    int cnt = 0, flag = 0;

    for (int i = 0; i < n; i++) {
        int bindex = n-i-1;
        if (bindex-cnt < 1) {
            flag = 1;
            break;
        }
        if (s.at(cnt) != s.at(bindex) && s.at(bindex) != 'a') break;
        if (s.at(cnt) == s.at(bindex)) cnt++; 
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}