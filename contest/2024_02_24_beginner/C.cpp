#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    int q;

    cin >> n >> s >> q;

    vector<int> now(26, 0);
    for (int i = 0; i < 26; i++) now[i] = i;

    for (int i = 0; i < q; i++) {
        char ci, di;
        cin >> ci >> di;

        int c = ci - 'a';
        int d = di - 'a';

        for (int j = 0; j < 26; j++) {
            if (now[j] == c) now[j] = d;
        }
    }

    for (int i = 0; i < (int)s.size(); i++) {
        cout << (char)(now[s[i] - 'a'] + 'a');
    }
    cout << endl;
 
    return 0;
}