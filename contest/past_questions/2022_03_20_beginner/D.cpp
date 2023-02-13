#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3, t1, t2, t3;

    cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;

    int cnt = 0;

    if (s1 == t1) cnt++;
    if (s2 == t2) cnt++;
    if (s3 == t3) cnt++;

    if (cnt == 1) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
