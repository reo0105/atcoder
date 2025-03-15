#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(505);

    for (int i = 0; i < h; i++) cin >> s.at(i);

    int a = 1000, b = 1000, c = -1, d = -1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s.at(i).at(j) == '#') {
                a = min(a, j);
                c = max(c, j);
                b = min(b, i);
                d = max(d, i);
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a <= j && j <= c && b <= i && i <= d) {
                if (s.at(i).at(j) == '.') {
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
            }
        }
    }

}