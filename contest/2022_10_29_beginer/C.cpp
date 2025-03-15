#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int ans = 0, dif_x, dif_y;
//     vector<vector<char>> data(9, vector<char>(9, 0));

//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {
//             cin >> data.at(i).at(j);
//         }
//     }
 
//     for (int i = 0; i < 9; i++) { //row
//         for (int j = 0; j < 9; j++) {
//             if (data.at(i).at(j) == '#') {
//                 for (int k = i+1; k < 9; k++) { //row
//                     for (int l = j; l < 9; l++) {
//                         if (data.at(k).at(l) == '#') {
//                             dif_x = k-i;
//                             dif_y = l-j;
                          
//                             if (0 <= (i+dif_y) && (i+dif_y) < 9 && 0 <= (j-dif_x) && (j-dif_x) < 9 && data.at(i+dif_y).at(j-dif_x) == '#') {
//                               if (0 <= (k+dif_y) && (k+dif_y) < 9 && 0 <= (l-dif_x) && (l-dif_x) < 9 && data.at(k+dif_y).at(l-dif_x) == '#') {
//                                ans++;
//                               }       
//                           }
//                         }
//                   }
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

int main()
{
    int dif_x, dif_y, cnt = 0;
    vector<vector<char>> data(9, vector<char>(9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> data.at(i).at(j);
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (data.at(i).at(j) == '#') {
                for (int y = i+1; y < 9; y++) {
                    for (int x = j; x < 9; x++) {
                        if (data.at(y).at(x) == '#') {
                            // dis = (y - i) * (y - i) + (x - j) * (x - j);
                            dif_x = x - j;
                            dif_y = y - i;
                            if (i+dif_x < 9 && j-dif_y >= 0 && data.at(i+dif_x).at(j-dif_y) == '#'){
                                // cout << i << j << " " << y << x << endl;
                                if (y+dif_x < 9 && x-dif_y >= 0 && data.at(y+dif_x).at(x-dif_y) == '#'){
                                    // cout << i << j << " " << y << x << endl;
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}