#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;

    string ans = "L";

    cin >> n;

    for (int i = 0; i < n; i++) ans.push_back('o');
    
    ans.push_back('n');
    ans.push_back('g');

    cout << ans << endl;
    
    return 0;
}