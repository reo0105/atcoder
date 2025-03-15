#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int num = 0;

    cin >> s;

    num = (s[3]-'0') * 100 + (s[4]-'0') * 10 + s[5]-'0';
    if (1 <= num && num <= 349 && num != 316) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}