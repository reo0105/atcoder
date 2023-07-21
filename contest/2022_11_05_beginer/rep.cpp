#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int h, w;
    cin >> h >> w;
    
    int si, sj;
    vector<string> c(h);
    for (int i = 0 ; i < h; i++) {
        cin >> c.at(i);
        for (int j = 0; j < w; j++) {
            if (c.at(i).at(j) == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    
    vector<int> dir_i0 = {-1, -1, -1, 0, 0, 1};
    vector<int> dir_j0 = {0, 0, 0, 1, 1, 0};

    vector<int> dir_i1 = {0, 1, 0, 1, 0, 0};
    vector<int> dir_j1 = {1, 0, -1, 0, -1, -1};

    vector<int> dir_i = {0, 1, 0, -1};
    vector<int> dir_j = {1, 0, -1, 0};

    for (int i = 0; i < 6; i++) {
        int pi = si + dir_i0.at(i);
        int pj = sj + dir_j0.at(i);

        int qi = si + dir_i1.at(i);
        int qj = sj + dir_j1.at(i);

        if (pi < 0 || pj < 0 || pi >= h || pj >= w) continue;
        if (qi < 0 || qj < 0 || qi >= h || qj >= w) continue;
        if (c.at(pi).at(pj) == '#' || c.at(qi).at(qj) == '#') continue;

        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist.at(si).at(sj) = 0;
        dist.at(pi).at(pj) = 1;
        queue<pii> que;
        que.push(make_pair(pi, pj));

        while(que.size()) {
            int ui = que.front().first;
            int uj = que.front().second;
            que.pop();

            for (int j = 0; j < 4; j++) {
                int vi = ui + dir_i.at(j);
                int vj = uj + dir_j.at(j);
            
                if (vi < 0 || vj < 0 || vi >= h || vj >= w) continue;
                if (dist.at(vi).at(vj) != -1 || c.at(vi).at(vj) == '#') continue;

                dist.at(vi).at(vj) = 1;
                que.push(make_pair(vi, vj));
            }
        }

        bool ok = 0;

        que.push(make_pair(qi, qj));

        while(que.size()) {
            int ui = que.front().first;
            int uj = que.front().second;
            que.pop();

            for (int j = 0; j < 4; j++) {
                int vi = ui + dir_i.at(j);
                int vj = uj + dir_j.at(j);
            
                if (vi < 0 || vj < 0 || vi >= h || vj >= w) continue;
                if (dist.at(vi).at(vj) == 1) {
                    ok = true;
                    break;
                } else if (dist.at(vi).at(vj) != -1 || c.at(vi).at(vj) == '#') continue;

                dist.at(vi).at(vj) = 2;
                que.push(make_pair(vi, vj));
            }

            if (ok) break;
        }

        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}