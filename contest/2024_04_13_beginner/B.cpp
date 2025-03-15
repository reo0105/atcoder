#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> alpha(26, 0);
    for (int i = 0; i < (int)s.size(); i++) {
        alpha[s[i]-'a']++;
    }

    vector<int> cnt(105, 0);
    for (int i = 0; i < 26; i++) {
        cnt[alpha[i]]++;
    }

    int ok = 1;
    for (int i = 1; i < 105; i++) {
        if (cnt[i] != 0 && cnt[i] != 2) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl; 

    return 0;
}