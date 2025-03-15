#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    char tmp;
    int a, b;
 
    cin >> s;
    cin >> a >> b;
 
    swap(s.at(a-1), s.at(b-1));
 
    cout << s << endl;
 
    return 0;
}