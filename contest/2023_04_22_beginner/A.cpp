#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (flag == 0 && s.at(i) == '|') flag++;
        else if (flag == 1 && s.at(i) == '*') flag++;
        else if (flag == 2 && s.at(i) == '|') flag++;    
    }
    
    if (flag == 3) cout << "in" << endl;
    else cout << "out" << endl;

    return 0;
}