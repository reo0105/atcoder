#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();

    for (int i = 0; i < n/2; i++) {
        swap(s.at(2*i), s.at(2*i+1));
    }
    cout << s << endl;

    return 0;
}