#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    string s;

    cin >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s.at(i) == 'v') count++;
        else if(s.at(i) == 'w') count+=2;
    }
    cout << count << endl;
    return 0;
}