#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h, w, r_s, c_s, r, c, n, q, l;
    char d;
    // map<char, int> dir;
    vector<vector<int, int>> wall_r(200002), wall_c(200002);

    // dir['L'] = -1;
    // dir['R'] = 1;
    // dir['U'] = -1;
    // dir['D'] = 1;

    cin >> h >> w >> r_s >> c_s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        wall_r.at(r).push_back(c);
        wall_r.at(c).push_back(r);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> d >> l;
        // for (int j = 0; j < l; j++) {
        //     switch (d) {
        //         case 'L':   c_s -= 1; break;
        //         case 'R':   c_s += 1; break;
        //         case 'U':   r_s -= 1; break;
        //         case 'D':   r_s += 1; break;
        //     }

        //     if (r_s < 1 || r_s > h || c_s < 1 || c_s > w || wall.count(make_pair(r_s, c_s))) {
        //         switch (d) {
        //             case 'L':   c_s += 1; break;
        //             case 'R':   c_s -= 1; break;
        //             case 'U':   r_s += 1; break;
        //             case 'D':   r_s -= 1; break;
        //         }
        //         break;
        //     }
        // }

        switch (d) {
            case 'L':   
                for (int i = 0; i < wall_r.at(r_s).size(); i++) {
                    if (wall_r.at(r_s).at(i) < c_s && c_s - l <  wall_r.at(r_s).at(i) && c_s - l > 0) {
                        c_s = wall_r.at(r_s).at(i) + 1;
                        break;
                    }
                }

                if (c_s - l < 0) {
                    c_s = 1;
                }

                break;

            case 'R':
                for (int i = 0; i < wall_r.at(r_s).size(); i++) {
                    if (wall_r.at(r_s).at(i) > c_s && c_s + l >  wall_r.at(r_s).at(i) && c_s + l < w) {
                        c_s = wall_r.at(r_s).at(i) - 1;
                        break;
                    }
                }

                if (c_s + l > w) {
                    c_s = w;
                }

                break;

            case 'U':   
                for (int i = 0; i < wall_c.at(c_s).size(); i++) {
                    if (wall_c.at(c_s).at(i) < r_s && r_s - l <  wall_c.at(c_s).at(i) && r_s - l > 0) {
                        r_s = wall_c.at(c_s).at(i) + 1;
                        break;
                    }
                }

                if (r_s - l < 0) {
                    r_s = 1;
                }

                break;

            case 'D':
                for (int i = 0; i < wall_r.at(r_s).size(); i++) {
                    if (wall_c.at(c_s).at(i) > r_s && r_s + l >  wall_c.at(c_s).at(i) && r_s + l < h) {
                        r_s = wall_r.at(c_s).at(i) - 1;
                        break;
                    }
                }

                if (r_s + l > h) {
                    r_s = w;
                }

                break;
              
        }


        cout << r_s << " " << c_s << endl; 
    }

    return 0;
}