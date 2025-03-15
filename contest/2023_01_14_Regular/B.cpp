#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> x(h+1, vector<char>(w+1));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> x.at(i).at(j);
        }
    }

    int q;
    // vector<pair<int, int> top(h);
    // pair<int, int> top = make_pair(1, 1);
    int now_h = 0, now_w = 0;
    // for (int i = 0; i < h; i++) {
    //     top.at(i) = make_pair(i, 0);
    // }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        // int now_h = top.first;
        // int now_w = top.second;
        cin >> a >> b;
        if (now_h < a && now_w < b) { // R1
            now_h = a - now_h - 1;
            now_w = b - now_w - 1;
        } else if (now_h < a) { // R2
            now_h = a - now_h - 1;
            now_w = b - now_w - 1 + w;
        } else if (now_h >= a && now_w < b) { //R3
            now_h = a - now_h - 1 + h;
            now_w = b - now_w - 1;
        } else { //R4
            now_h = a - now_h - 1 + h;
            now_w = b - now_w - 1 + w;
        }
        // top = make_pair()
    }

    // cout << now_h << " " << now_w << endl;

    vector<vector<char>> ans(h+1, vector<char>(w+1));
    if (q % 2 == 0) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ans.at((now_h+i)%h).at((now_w+j)%w) = x.at(i).at(j); 
            }
        }
    } else {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ans.at((now_h-i+h)%h).at((now_w-j+w)%w) = x.at(i).at(j); 
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans.at(i).at(j);
        }
        cout << endl;
    }


    return 0;
}