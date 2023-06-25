#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int ha, wa, hb, wb, hx, wx;
    vector<string> a(10);
    vector<string> b(10);
    vector<string> x(10);

    cin >> ha >> wa;
    for (int i = 0; i < ha; i++) cin >> a.at(i);
    cin >> hb >> wb;
    for (int i = 0; i < hb; i++) cin >> b.at(i);
    cin >> hx >> wx;
    for (int i = 0; i < hx; i++) cin >> x.at(i);

    vector<pi> s;
    for (int i = 0; i < ha; i++) {
        for (int j = 0; j < wa; j++) {
            if (a.at(i).at(j) == '#') s.push_back(make_pair(i, j));
        }
    }

    int si = (int)s.size();


    for (int i = 0; i < hx; i++) {
        for (int j = 0; j < wx; j++) {
            if (x.at(i).at(j) == '#') {
                for (int k = 0; k < si; k++) {
                    int ok = 1;
                    int px = s.at(k).first;
                    int py = s.at(k).second;

                    for (int l = 0; l < si; l++) {
                        if (k == l) continue;

                        int dx = s.at(l).first - px;
                        int dy = s.at(l).second - py;

                        if (i+dy < 0 || i+dy >= hx || j+dx < 0 || j + dx >= wx) { ok = 0; break; }
                        if (x.at(i+dy).at(j+dx) == '.') { ok = 0; break; }

                    }
                }
            }
        }
    }


    int si = (int)s.size();

    return 0;
}