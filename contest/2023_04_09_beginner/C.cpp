#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(105);

    for (int i =0; i < h; i++) cin >> s.at(i);

    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s.at(i).at(j) == 'T') cnt++;
            else cnt = 0;

            if (cnt == 2) {
                s.at(i).at(j-1) = 'P';
                s.at(i).at(j) = 'C';
                cnt =0;
            }
        }
        cnt = 0;
    }

    for (int i = 0; i < h; i++) {
        cout << s.at(i) << endl;
    }

    return 0;
}