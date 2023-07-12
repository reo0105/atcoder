#include <bits/stdc++.h>
using namespace std;

vector<string> S(505);
int h, w;
vector<int> dir_x = {1, 0, -1, 0};
vector<int> dir_y = {0, -1, 0, 1};
vector<vector<bool>> dist(505, vector<bool>(505, false));
bool dfs(int i, int j, int s)
{
    // cout << i << " " << j << " " << s << endl;
    dist.at(i).at(j) = true;
    if (i == h-1 && j == w-1) return true;
    for (int k = 0; k < 4; k++) {
        int ni = i + dir_y.at(k);
        int nj = j + dir_x.at(k);
        if (ni < 0 || ni >= h || nj < 0 || nj >= w || dist.at(ni).at(nj)) continue;
        // cout << "in " << ni << " " << nj << " " << s << endl;

        if (s == 0 && S.at(ni).at(nj) == 'n') {
            if(dfs(ni, nj, 1)) return true;
        } else if (s == 1 && S.at(ni).at(nj) == 'u') {
            if(dfs(ni, nj, 2)) return true;
        } else if (s == 2 && S.at(ni).at(nj) == 'k') {
            if(dfs(ni, nj, 3)) return true;
        } else if (s == 3 && S.at(ni).at(nj) == 'e') {
            if(dfs(ni, nj, 4)) return true;
        } else if (s == 4 && S.at(ni).at(nj) == 's') {
            if(dfs(ni, nj, 0)) return true;
        }
    }

    return false;
}


int main()
{
    cin >> h >> w;

    for (int i = 0; i < h; i++) cin >> S.at(i);


    if (S.at(0).at(0) == 's') {
//         vector<vector<vector<bool>>> dp(505, vector<vector<bool>>(505, vector<bool>(5, false)));

//         dp.at(0).at(0).at(0) = true;

//         for (int i = 0; i < h; i++) {
//             for (int j = 0; j < w; j++) {
//                 for (int k = 0; k < 5; k++) {
//                     for (int l = 0; l < 4; l++) {
//                         int ni = i + dir_y.at(l);
//                         int nj = j + dir_x.at(l);
// // if ((i >= 1 && dp.at(i-1).at(j).at((k-1+5)%5)) || (j >= 1 && dp.at(i).at(j-1).at((k-1+5)%5))) dp.at(i).at(j).at(k) = true;
//                         if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
//                         if (dp.at(i).at(j).at((k-1+5)%5)) dp.at(ni).at(nj).at(k) = true; 
//                     }
//                 }
//             }
//         }

//         for (int i = 0; i < 5; i++) {
//             if (dp.at(h-1).at(w-1).at(i)) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }

//         cout << "No" << endl;

        if (dfs(0, 0, 0)) cout << "Yes" << endl;
        else cout << "No" << endl;

    } else {
        cout << "No" << endl;
    }
 

    return 0; 
}