#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int sz = (int)s.size();

    map<char, int> a, b;
    map<char, int> x;

    set<char> moji;
    
    moji.insert('a');
    moji.insert('t');
    moji.insert('c');
    moji.insert('o');
    moji.insert('d');
    moji.insert('e');
    moji.insert('r');
    int cnta = 0, cntb = 0;
    for (int i = 0; i < sz; i++) {
        if (s.at(i) != '@') a[s.at(i)]++;
        else cnta++;
    } 
    
    for (int i = 0; i < sz; i++) {
        if (t.at(i) != '@') b[t.at(i)]++;
        else cntb++;
    }

    for (char p = 'a'; p <= 'z'; p++) {
        x[p] = max(0, abs(a[p] - b[p]));
    }


    int cnt = 0;
    for (auto pi : x) {
        if (!moji.count(pi.first) && pi.second != 0) {cout << "No" << endl; return 0;}
        else if (pi.second != 0) cnt += pi.second;
    }


    if (cnt > (cnta + cntb)) { cout << "No" << endl; return 0;}

    cout << "Yes" << endl;

    return 0;
}