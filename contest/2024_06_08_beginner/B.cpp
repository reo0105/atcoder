#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int sz = (int)s.size();

    int small = 0, large = 0; 
    for (int i = 0; i < sz; i++) {
        if ('a' <= s[i] && s[i] <= 'z') small++;
        else large++;
    }

    if (small > large) {
        for (auto &c : s) {
            if ('A' <= c && c <= 'Z') c = tolower(c);
            cout << c;
        } 
    } else {
        for (char &c : s) {
            if ('a' <= c && c <= 'z') c -= 32;
            cout << c;
        } 
    }

    return 0;
}