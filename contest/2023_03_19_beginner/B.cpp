#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        string s;
        for (int j = 0; j < w; j++) {
            int a;
            cin >> a;
            if (a == 0) s.push_back('.');
            else s.push_back('A' + a-1);
        }
        cout << s << endl;
    }

    return 0;
}