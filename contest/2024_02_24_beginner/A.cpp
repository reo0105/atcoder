#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;


    int cnt = 1;
    int first = s[0] - 'a';    
    int id = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (first == s[i] - 'a') cnt++;
        else id = i;
    }

    if (cnt == 1) cout << 1 << endl;
    else cout << id+1 << endl;

}